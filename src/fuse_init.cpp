/*
  Copyright (c) 2016, Antonio SJ Musumeci <trapexit@spawn.link>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include "config.hpp"
#include "ugid.hpp"

#include <fuse.h>

namespace FUSE
{
  void *
  init(fuse_conn_info *conn_)
  {
    ugid::init();

    conn_->want |= FUSE_CAP_ASYNC_READ;
    conn_->want |= FUSE_CAP_ATOMIC_O_TRUNC;
    conn_->want |= FUSE_CAP_BIG_WRITES;
    conn_->want |= FUSE_CAP_DONT_MASK;
    conn_->want |= FUSE_CAP_IOCTL_DIR;

    return &Config::get_writable();
  }
}