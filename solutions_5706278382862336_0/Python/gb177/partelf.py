#!/usr/bin/python

import sys
from fractions import Fraction as F

def Ni(): return tuple(map(int, sys.stdin.readline().split()))
def Ns(): return tuple(sys.stdin.readline().split())

def tobin(f):
    a = []
    for i in range(50):
        f = 2 * f
        if f >= 1:
            a.append(1)
            f -= 1
        else:
            a.append(0)
        if f == 0:
            break

    return a

T = Ni()[0]
for t in range(1, T + 1):
    P, Q = map(int, Ns()[0].split("/"))
    pq = F(P, Q)
    b = tobin(pq)
    if len(b) <= 40:
        answer = str(b.index(1) + 1)
    else:
        answer = "impossible"

    print "Case #%d: %s" % (t, answer)

