#!/usr/bin/env python
# -*- encoding: utf-8 -*-
# Author: Yifu Yu <root@jackyyf.com>

T = input()

def toInt(lst, k):
    ret = 0
    for n in lst:
        ret = ret * k + (n if n < k else 0)
    return ret

for t in range(T):
    k, c, s = map(int, raw_input().split())
    print 'Case #%d:' % (t + 1),
    if c * s < k:
        print 'IMPOSSIBLE'
    else:
        now = 0
        pos = []
        while now < k:
            t = range(now, now + c)
            pos.append(toInt(t, k) + 1)
            now += c
        print ' '.join(map(str, pos))
