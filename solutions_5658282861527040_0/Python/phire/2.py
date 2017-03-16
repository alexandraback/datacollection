#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        A, B, K = map(int, sys.stdin.readline().split())
        ret = 0
        for a in xrange(A):
            for b in xrange(B):
                if (a & b) < K:
                    ret += 1
        print "Case #" + str(t) + ": " + str(ret)

if __name__ == '__main__':
    main()
