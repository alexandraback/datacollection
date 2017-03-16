# Round 1C 2014
# Problem C. Enclosure
# MichelJ

import sys
import logging
import StringIO
from itertools import *
from math import factorial
from collections import *

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def points(a,b):
    if a==1:
        return b
    if b==1:
        return a
    if a==2 or b==2:
        return a*b
    return a*b-4
    
def stones(a,b):
    if a==1:
        return b
    if b==1:
        return a
    if a==2 or b==2:
        return a*b
    return 2*(a+b-4)

def solve(n,m,k):
    mins = n*m
    for a in xrange(1,n+2):
        for b in xrange(1,m+2):
            p = points(a,b)
            s = stones(a,b)
#            print a,b,p,s
            if p>=k:
                if s<mins:
                    mins=s
    return str(mins)
    return "yo!"


def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        n,m,k = map(int,raw_input().split(" "))
        print 'Case #%d: %s' % (tc, solve(n,m,k))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""2
4 5 8
3 5 11
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
