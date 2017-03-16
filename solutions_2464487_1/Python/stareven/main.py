#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import sys

INF = 10 ** 10

def ReadIn():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        r, t = [int(x) for x in raw_input().split()]
        yield case, r, t

def Solve(x, y):
    def calc(k):
        return 2 * k * x + (2 * k - 1) * k

    l, r = 0, INF
    while l < r:
        mid = (l + r + 1) >> 1
        if calc(mid) <= y:
            l = mid
        else:
            r = mid - 1
    return l


if __name__ == '__main__':
    for case, r, t in ReadIn():
        print 'Case #%d: %d' % (case, Solve(r, t))
