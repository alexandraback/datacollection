#!/usr/bin/env python
# coding:utf-8
# Copyright (C) dirlt

import sys
fh = sys.stdin
case_num = int(fh.readline())
for c in range(case_num):
    (K, C, S) = map(lambda x: int(x), fh.readline().split())
    assert(K == S)
    print('Case #%d: %s' % (c + 1, ' '.join(map(lambda x: str(x), range(1, K + 1)))))
