#!/usr/bin/env python

from __future__ import print_function

def readSolveCase():
    A, B, K = map(int, raw_input().split())
    ways = 0
    for a in xrange(A):
        for b in xrange(B):
            if a & b < K:
                ways += 1
    return ways

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print('Case #{}: {}'.format(t, readSolveCase()))

if __name__ == "__main__":
    main()
