# Round 1C 2014
# Problem A. Part Elf
# MichelJ

import sys
import logging
import StringIO
from itertools import chain
from fractions import *

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def solve(p,q):
    f = Fraction(p,q)
    d = f.denominator
    n = f.numerator
    res=0
    while d%2==0:
        res+=1
        d = d/2
    if d!=1:
        return "impossible"
    while n>1:
        res-=1
        n//=2
    return str(res)

def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        p,q = map(int,raw_input().split("/"))
        print 'Case #%d: %s' % (tc, solve(p,q))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""5
1/2
3/4
1/4
2/23
123/31488
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
