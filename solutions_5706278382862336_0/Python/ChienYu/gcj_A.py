from sys import stdin
from math import log, ceil
from fractions import Fraction

def each_case(P, Q):
    P, Q = map(int, str(Fraction(P, Q)).split('/'))
    lQ = int(log(Q, 2))
    if 2**lQ == Q:
        return int(ceil(lQ - log(P, 2)))
    else:
        return 'impossible'

T = int(stdin.readline())
for t in xrange(1,T+1):
    P, Q = map(int, stdin.readline().split('/'))
    print 'Case #{}: {}'.format(t, each_case(P, Q))
stdin.close()
