#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def solve(s):
    s = map(int, s.split())
    N = s[0]
    S = s[1]
    p = s[2]
    t = s[3:]
    assert len(t) == N
    if p == 0:
        return N
    if p == 1:
        return len([x for x in t if x])
    good = 0
    maybe = 0
    for x in t:
        if x >= p*3 - 2:
            good += 1
        elif x >= p*3 - 4:
            maybe += 1
    return good + min(maybe, S)

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1, T+1):
        print "Case #" + str(i) + ": " + str(solve(sys.stdin.readline().strip()))

if __name__ == '__main__':
    main()
