import sys, numpy as np
from itertools import combinations
from operator import itemgetter
from collections import deque, defaultdict

literals = [ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" ]
it = defaultdict(list)
for x, s in enumerate(literals):
    for c in s:
        it[c].append( x )

def makeit( T ):
    U = np.zeros( [ len(T), 10 ] )
    V = sorted(T)
    for n, c in enumerate(V):
        v = T[c]
        for i in v: 
            U[ n, i ] += 1
    return U, V

U, V = makeit( it )
VD = dict([ (c,n) for n, c in enumerate(V)  ])
#for u, v in zip(U,V): print u, v

def makey ( s ):
    Y = np.zeros( len(V) )
    for c in s:
        Y[ V.index(c) ] += 1
        #Y[ VD[c] ] += 1
    return Y

def solve( s ):
    s = makey(s)
    ans = np.rint( np.linalg.lstsq( U, s )[0] ).astype(int)
    return "".join( [ str(n)*x for n,x in enumerate(ans) ] )
    

def main():
    f = open( sys.argv[1] )
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        S = f.next().strip()
        print "Case #{0}: {1}".format( case, solve(S) )
        

if __name__ == "__main__":
    main()
