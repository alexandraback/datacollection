#!/usr/bin/env python

from __future__ import print_function

def readSolveCase():
    P, Q = map(int, raw_input().split('/'))
    if 2**40 * P % Q != 0:
        return 'impossible'
    numAncientElves = 2**40 * P / Q
    return 40 - len('{:b}'.format(numAncientElves)) + 1

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print('Case #{}: {}'.format(t, readSolveCase()))

if __name__ == "__main__":
    main()
