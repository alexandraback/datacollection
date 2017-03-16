import sys, numpy as np
from itertools import combinations
from operator import itemgetter
from collections import defaultdict

def hist( v ):
    d = defaultdict(int)
    for i in v:
        for j in i:
            d[j] += 1
    return d

def goodfit( board, v, nrow, ncol, skiprow, skipcol ):
    pass#if 


def solve( N, M ):
    """S0 = map( set, M )
    print S0
    S1 = map( set, zip(*M) )
    D1 = map( hist, zip(*M) )
    print zip(*M)
    print S1
    print D1
    
    possible = []
    for i, row in enumerate(S0):
        for j, col in enumerate(S1):
            if row.issubset( col ) and D1[j][ M[i][j] ] > 1:
                #print i, j, D1[j][ M[i][j] ]
                print "{0}th row {1} can be used as {2}th column {3}".format( i, M[i], j, col )
                possible.append( (i,j) )"""
    
    #print hist(M)
    h = hist(M)
    #print [ i for i,j in h.items() if j & 1 ]
    
    return sorted([ i for i,j in h.items() if j & 1 ])
    '''M.sort()
    
    board = np.array( [ [None]*N for i in range(N) ] )
    board[:,0] = M[0]
    nrow, ncol = 1, 1
    skiprow, skipcol = False, False
    
    for v in M[1:]:
        cand = goodfit( board, v, nrow, ncol, skiprow, skipcol )

    return []'''

def main():
    f = open( sys.argv[1] )
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        N = int( f.next() )
        M = [ map(int, f.next().strip().split()) for i in range(2*N-1) ]
        print "Case #{0}: {1}".format(  \
            case, \
            " ".join( map(str, solve(N,M) ) ) \
            )


if __name__ == "__main__":
    main()
