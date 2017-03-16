import sys, itertools as itt, StringIO, re
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

def selfdup ( G ):
    return [ i for i in range(1, len(G)) if G[i:] == G[:-i] ]

def expected ( KB, S, G ):
    pat = re.compile( r'(?=(%s))' % G )
    ans = 0
    M = 0
    for output in itt.product( KB, repeat=S ):
        x = len( pat.findall( "".join(output) ) )
        ans += x
        M = max(M, x)
    return float(ans) / (len(KB)**S), M

def solve( K, L, S, KB, G ):
    a, b = expected( KB, S, G )
    return b-a

def main(f):
    T = int( f.next() )
    for i in range(T):
        K, L, S = linearg( f, int )
        KB = f.next().strip()
        G = f.next().strip()
        print "Case #{0}: {1:.7}".format( i+1, solve( K, L, S, KB, G ) )
        sys.stdout.flush()

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
4
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ
""" ))

