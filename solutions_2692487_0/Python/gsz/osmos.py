#!/usr/bin/env python

from __future__ import print_function

def readSolveCase():
    A, N = map(int, raw_input().split())
    motes = map(int, raw_input().split())
    motes.sort()
    if A == 1:
        return N
    bestBailout = N
    edits = 0
    size = A
    for (i, mote) in enumerate(motes):
        bestBailout = min(edits + N - i, bestBailout)
        while mote >= size:
            size += size - 1
            edits += 1
        size += mote
        if edits > bestBailout:
            break
    return min(edits, bestBailout)

def main():
    T = int(raw_input())
    for casenum in xrange(1, T+1):
        print('Case #', casenum, ': ', readSolveCase(), sep='')

if __name__ == '__main__':
    main()

