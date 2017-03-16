#!/usr/bin/env python

from __future__ import print_function

def solveCase(X, Y):
    incX = 'WE'
    incY = 'SN'
    if X < 0:
        X = -X
        incX = ''.join(reversed(incX))
    if Y < 0:
        Y = -Y
        incY = ''.join(reversed(incY))
    return incX * X + incY * Y

def main():
    T = int(raw_input())
    for casenum in xrange(1, T+1):
        X, Y = map(int, raw_input().split())
        print('Case #', casenum, ': ', solveCase(X, Y), sep='')

if __name__ == '__main__':
    main()
