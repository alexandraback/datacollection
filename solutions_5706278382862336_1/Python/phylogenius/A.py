import math
import sys
from fractions import Fraction as F

p2 = lambda n: n != 0 and n & (n-1) == 0

def g(f):
    d = F(1,1)
    i = 0
    while d > f:
        i += 1
        d = F(1, 2 ** i)
    return i

T = int(sys.stdin.readline())
for x in xrange(1, T+1):
    f = F(sys.stdin.readline())
    if not p2(f.denominator):
        y = 'impossible'
    else:
        #y = int(math.log(math.ceil(F(f.denominator, f.numerator)), 2))
        y = g(f)
    print 'Case #{}: {}'.format(x, y)

