#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from bisect import bisect_left, bisect_right

def ReadIn():
    cases = int(raw_input())
    for case in xrange(1, cases + 1):
        lower, upper = [int(x) for x in raw_input().split()]
        yield case, lower, upper

def Init():
    global tab
    tab = []
    for x in (a ** 2 for a in xrange(1, 10000001) if str(a) == str(a)[::-1]):
        if str(x) == str(x)[::-1]:
            tab.append(x)

def Solve(lower, upper):
    global tab
    return bisect_right(tab, upper) -  bisect_left(tab, lower)

if __name__ == '__main__':
    Init()
    for case, lower, upper in ReadIn():
        print 'Case #%d: %d' % (case, Solve(lower, upper))
