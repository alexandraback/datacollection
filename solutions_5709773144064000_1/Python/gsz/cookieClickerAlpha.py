#!/usr/bin/env python

from __future__ import print_function

def readSolveCase():
    C, F, X = map(float, raw_input().split())
    threshold = X/C - 2/F - 1  
    farms = 0
    time = 0.0
    while farms < threshold:
        time += C / (farms * F + 2)
        farms += 1
    time += X / (farms * F + 2)
    return time

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        print('Case #{}: {:.7f}'.format(t, readSolveCase()), sep='')

if __name__ == "__main__":
    main()
