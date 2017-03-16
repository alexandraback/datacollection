#!/usr/bin/env python

from __future__ import print_function

vowels = set('aeiou')

def solveCase(L, n):
    nValues = [0] * (len(L) + 1)
    bigBlockEnd = -1
    curBlockSize = 0
    for i in xrange(1, len(nValues)):
        if L[i-1] not in vowels:
            curBlockSize += 1
        else:
            curBlockSize = 0
        if curBlockSize >= n:
            bigBlockEnd = i-1
        increment = max(0, bigBlockEnd - n + 2)
        nValues[i] = nValues[i-1] + increment
    return nValues[-1]

def main():
    T = int(raw_input())
    for casenum in xrange(1, T+1):
        L, n = raw_input().split()
        n = int(n)
        print('Case #', casenum, ': ', solveCase(L, n), sep='')

if __name__ == '__main__':
    main()
