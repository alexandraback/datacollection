import sys, itertools as itt, StringIO
#import heapq, bisect, numpy, math
from collections import defaultdict, namedtuple, deque, Counter
from operator import itemgetter
from types import FunctionType

lines = lambda f: "\n".join( map( str, f ) )
def linearg ( f, fmt = None ):
    if fmt == None:
        return f.next().strip().split()
    elif isinstance( fmt, (type,FunctionType) ):
        return [ fmt(i) for i in f.next().strip().split() ]
    else:
        return [ i(j) for i, j in zip( fmt, f.next().strip().split() ) ]

def solve( R, C, W ):
    return ( (C-1) / W ) + W + (R-1)*( C/W )

def main(f):
    T = int( f.next() )
    for i in range(T):
        R, C, W = linearg( f, int )
        print "Case #{0}: {1}".format( i+1, solve( R, C, W ) )

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
3
1 4 2
1 7 7
2 5 1""" ))

