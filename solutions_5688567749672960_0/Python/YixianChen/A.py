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

def flip(x):
    y = 0
    while x:        
        y = y*10 + (x % 10)
        x /= 10
    return y

def calc( ANS, k):
    for i in range(1, k):
        a = ANS[i]+1
        j = i+1
        if j < k:
            ANS[j] = min( ANS[j], a )
        j = flip(i)
        if j < k:
            ANS[j] = min( ANS[j], a )

ANS = [ 10**6 ] * (10**6+1)
ANS[:2] = [0,1]
calc(ANS, 10**6+1)

def solve( N ):
    return ANS[N]

def main(f):
    T = int( f.next() )
    for i in range(T):
        N = int(f.next())
        print "Case #{0}: {1}".format( i+1, solve( N ) )

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
3
1
19
23
""" ))

