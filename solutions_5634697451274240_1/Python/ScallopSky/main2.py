#! /usr/bin/env python

import sys
sys.setrecursionlimit(1000000)

T = int(raw_input())
for Case in range(1, T+1):
    print "Case #%d: " % Case,
    s = raw_input()
    step = 0

    if s[-1] == '-':
        step += 1
    for i in range(len(s)-1):
        if s[i] != s[i+1]:
            step += 1

    print step
