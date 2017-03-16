#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os


def solve(X, R, C):
    r = min(R, C)
    c = max(R, C)
    if X == 1:
        return "GABRIEL"
    if X == 2:
        return "RICHARD" if (R & 1) and (C & 1) else "GABRIEL"
    if (X + 1) / 2 > r or (r * c) % X:
        return "RICHARD"
    if X == 3:
        return "GABRIEL"
    if X == 4:
        if r == 2:
            return "RICHARD"
        else:
            return "GABRIEL"


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        X, R, C = map(int, sys.stdin.readline().split())
        print "Case #%d: %s" % (t, solve(X, R, C))

if __name__ == '__main__':
    main()
