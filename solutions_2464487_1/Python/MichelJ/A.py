# Google Code Jam 2013 Round 1A
# Problem A. Bullseye
# mjacquem1

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

from math import sqrt

def R(r,n):
    return (2*n*r+2*n*n-n)

# Stupid one
def bullseye1(r,t):
    n =1
    while R(r,n)<=t:
        n += 1
    return n-1

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

def bullseye2(r,t):
    a=2
    b=2*r-1
    c=-t
    delta = b*b-4*a*c
    rdelta = isqrt(delta)
    x = (rdelta - b) // (2*a)
    return x


def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        (r,t) =  map(int,raw_input().split(' '))
        print 'Case #%d: %s' % (tc, bullseye2(r,t))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""5
1 9
1 10
3 40
1 1000000000000000000
10000000000000000 1000000000000000000
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
