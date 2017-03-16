#!/usr/bin/env python

from sys import stdin
from numpy import array, log2, floor, ceil


T = int(stdin.readline())

for t in range(T):
    print "Case #%d:" % (t+1),

    P, Q = array(stdin.readline().split("/")).astype(int)
    QQ = Q
    while QQ % 2 == 0: QQ /= 2
    if P % QQ != 0:
        print "impossible"
    else:
        print int(ceil(log2(Q) - log2(P)))
