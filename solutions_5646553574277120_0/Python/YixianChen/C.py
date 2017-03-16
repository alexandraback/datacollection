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

def solve( C, D, V, coins ):
    s, t = set([0]), set(range(1, V+1))
    for x in coins:
        i, j = itt.tee( itt.chain(*[ range( v + x, min(v+ C*x+1, V+1), x ) for v in s ]) )
        #j = itt.chain(*[ range( v + x, min(v+ C*x+1, V+1), x ) for v in s ])
        s.update( i )
        t.difference_update( j )
    ans = 0
    while len(t)>0:
        ans += 1
        x = min(t)
        #print "add", x
        #j = itt.chain(*[ range( v + x, min(v+ C*x+1, V+1), x ) for v in s ])
        i, j = itt.tee( itt.chain(*[ range( v + x, min(v+ C*x+1, V+1), x ) for v in s ]) )
        s.update(i)
        t.difference_update( j )
    return ans

def main(f):
    T = int( f.next() )
    for i in range(T):
        C, D, V = linearg( f, int )
        coins = linearg( f, int )
        print "Case #{0}: {1}".format( i+1, solve( C, D, V, coins ) )
        sys.stdout.flush()

if len(sys.argv) >= 2:
    main(open(sys.argv[1]))
else:
    main(   StringIO.StringIO(  """\
2
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100""" ))

