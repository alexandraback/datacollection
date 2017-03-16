import sys, numpy as np
from itertools import combinations
from operator import itemgetter
from collections import deque, defaultdict


def solve( N, topics ):
    if N==1:
        return 0
    sets = map( frozenset, zip(*topics) )
    for k in range(1, N):
        for comb in combinations( topics, k ):
            mysets = map( frozenset, zip(*comb) )
            if mysets == sets:
                return N-k
    return 0

def main():
    f = open( sys.argv[1] )
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        N = int( f.next().strip() )
        topics = [ f.next().strip().split() for i in range(N) ]
        print "Case #{0}: {1}".format( case, solve( N, topics ) )
        

if __name__ == "__main__":
    main()
