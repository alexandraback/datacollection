# GCJ 2014 Round 1C, Problem A, Jeremy Holman

import sys
from fractions import Fraction

T = int(sys.stdin.readline().strip())

for i in xrange(T):
    P, Q = map(int, sys.stdin.readline().strip().split("/"))
    frac = Fraction(P, Q)
    P = frac.numerator
    Q = frac.denominator

    answer = 0
    possible = True
    while possible and Q > 1:
        if Q % 2:
            possible = False
        answer += 1
        Q /= 2
    while P > 1:
        answer -= 1
        P /= 2

    print "Case #%d:" % (i+1),
    if possible:
        print answer
    else:
        print "impossible"



