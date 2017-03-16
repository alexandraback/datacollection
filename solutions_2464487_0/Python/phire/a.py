#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def main():
    T = int(sys.stdin.readline())
    for i in xrange(1, T+1):
        r, t = map(int, sys.stdin.readline().strip().split())
        mx = 2 * (10 ** 18)
        mn = 0
        while mn < mx - 1:
            mid = (mx + mn) / 2
            if 2 * mid * mid + (2 * r - 1) * mid <= t:
                mn = mid
            else:
                mx = mid
        print "Case #" + str(i) + ":", mn


if __name__ == '__main__':
    main()
