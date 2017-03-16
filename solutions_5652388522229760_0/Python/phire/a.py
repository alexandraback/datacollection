#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def solve(N):
    a = [False] * 10
    if N == 0:
        return "INSOMNIA"
    i = N
    while True:
        t = i
        while t:
            a[t % 10] = True
            t /= 10
        if all(a):
            return i
        i += N

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1, T+1):
        N = int(sys.stdin.readline())
        print "Case #%s: %s" % (i, solve(N))

if __name__ == '__main__':
    main()
