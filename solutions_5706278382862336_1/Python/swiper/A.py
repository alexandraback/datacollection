def gcd(x, y):
    if y == 0:
        return x
    if x > y:
        return gcd(y, x%y)
    else:
        return gcd(y, x)
def powerof2(x):
    return ((x != 0) and not (x & (x - 1)))

import math
def solve(P, Q):
    g = gcd(P, Q)
    Q = Q/g
    P = P/g
    if P == 0 or not powerof2(Q):
        return "impossible"
    i = 0
    while P < Q:
        P *= 2
        i += 1
    return str(i)
from sys import stdin

C = int(stdin.readline())
for c in range(C):
    P, Q = map(int, stdin.readline().split('/'))
    print "Case #%d: %s" % (c+1, solve(P, Q))

