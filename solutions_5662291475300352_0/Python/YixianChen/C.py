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

class Graph ( defaultdict ):
    def __init__ ( self, pairs ):
        defaultdict.__init__( self, list )
        for i, j in pairs:
            self[i].append(j)
            self[j].append(i)

def solve( G ):
    if len(G)==1:
        return 0
    if len(G)==2:
        if G[0][2] == G[1][2]:
            return 0
        else:
            return 1

def main(f):
    T = int( f.next() )
    for i in range(T):
        N = int( f.next() )
        G = [ linearg( f, int ) for k in range(N) ]
        print "Case #{0}: {1}".format( i+1, solve( G ) )

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
3
4
1 1 12
359 1 12
2 1 12
358 1 12
2
180 1 100000
180 1 1
1
180 2 1
""" ))

