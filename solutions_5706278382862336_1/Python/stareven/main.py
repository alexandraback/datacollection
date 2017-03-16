#!/usr/bin/env python

from fractions import gcd
from math import log

def ReadIn():
    cases = int(input().strip())
    for case in range(1, cases + 1):
        P, Q = [int(x) for x in input().strip().split('/')]
        yield case, P, Q

def Solve(P, Q):
    d = gcd(P, Q)
    P, Q = P // d, Q // d
    if P <= Q and -Q & Q == Q:
        return int(log(Q, 2)) - int(log(P, 2))
    return 'impossible'

if __name__ == '__main__':
    for case, P, Q in ReadIn():
        print('Case #%d: %s' % (case, Solve(P, Q)))

