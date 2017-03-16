#!/usr/bin/env python

from sys import stdin

ntest = input()

for test in xrange(ntest):
    a, n = [int(i) for i in stdin.readline().strip().split(' ')]
    motes = sorted([int(i) for i in stdin.readline().strip().split(' ')])
    moves = 0
    minmoves = n
    if a > 1:
        for i, s in enumerate(motes):
            while a <= s:
                a = 2 * a - 1
                moves += 1
            a += s
            minmoves = min(minmoves, moves + (n - 1) - i)
    print("Case #{}: {}".format(test+1, minmoves))
