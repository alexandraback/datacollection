#!/usr/bin/env python

from sys import stdin
from math import ceil

T = int(stdin.readline())

for t in range(T):
    wds = stdin.readline().split()
    C = float(wds[0])
    F = float(wds[1])
    X = float(wds[2])

    N = int(ceil((X*F - 2*C) / (C*F) - 1))
    if N < 0: N = 0

    ret = 0.
    for n in range(N): ret += C / (2 + n * F)
    ret += X / (2 + N * F)

    print "Case #%d:" % (t+1),
    print "%.7f" % ret
