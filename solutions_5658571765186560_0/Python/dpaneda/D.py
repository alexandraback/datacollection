#!/usr/bin/python2

import sys


def solve():
    X, R, C = map(int, sys.stdin.readline().split())

    if X > max(R, C):
        return "RICHARD"

    if (R * C) % X:
        return "RICHARD"

    n = X / 2

    if X % 2:
        n += 1

    if n > min(R, C):
        return "RICHARD"

    if X > 3:
        if min(R, C) < 3:
            return "RICHARD"

    return "GABRIEL"


num = int(sys.stdin.readline())
for case in range(1, num + 1):
    print "Case #{0}: {1}".format(case, solve())
