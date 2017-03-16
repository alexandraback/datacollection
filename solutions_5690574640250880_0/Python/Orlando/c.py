#!/usr/bin/env python

import sys

pr = sys.stdout.write

t = int(raw_input())

for caseno in xrange(1, t+1):
    r, c, m = map(int, raw_input().split())
    print "Case #%d:" % caseno
    s = r * c
    if s <= 2:
        for i in xrange(r):
            for j in xrange(c):
                if m > 0:
                    pr("*")
                    m -= 1
                elif i == r-1 and j == c-1:
                    pr("c")
                else:
                    pr(".")
            pr("\n")
        continue
    if r == 1 or c == 1:
        for i in xrange(s):
            if m > 0:
                pr("*")
                m -= 1
            elif i < s-1:
                pr(".")
            else:
                pr("c")
            if c == 1:
                pr("\n")
        if r == 1:
            pr("\n")
        continue
    if s - m < 4:
        print "Impossible"
        continue
    pre = 0
    for i in xrange(r-2):
        if m > 0 and r-i > 2 and r-i % m == 0:
            pre += 1
            m -= r-i
        for j in xrange(c):
            if j < pre:
                pr("*")
                continue
            if m == 1:
                if j < c-2 or j == c-1:
                    pr("*")
                    m -= 1
                else:
                    for k in xrange(j, c):
                        pr(".")
                    break
            elif m > 0:
                pr("*")
                m -= 1
            else:
                pr(".")
        pr("\n")
    m0 = m // 2
    m1 = m // 2
    for i in xrange(2):
        for j in xrange(c):
            if j < pre:
                pr("*")
                continue
            if j < c-2:
                if (i == 0 and m0 > 0) or (i == 1 and m1 > 0):
                    pr("*")
                    if i == 0:
                        m0 -= 1
                    else:
                        m1 -= 1
                else:
                    pr(".")
            elif i == 1 and j == c-1:
                pr("c")
            else:
                pr(".")
        pr("\n")
    continue
