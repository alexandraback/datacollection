import sys, numpy as np
from itertools import combinations, product, cycle
from operator import itemgetter
from collections import deque, defaultdict
import heapq, pprint

#1 1 1
#1 2 2
#1 3 3
#2 1 2
#2 2 3
#2 3 1
#3 1 3
#3 2 1
#3 3 2

def solve( J,P,S,K ):
    #n, m = J*P*S, J*P*K
    #for j,p in product( range(1,J+1), range(1,P+1) ):
    #ans = [ "{0} {1} {2}".format(j,p,k) for j,p,k in product( range(1,J+1), range(1,P+1), range(1,min(S,K)+1) ) ]
    #print "J,P,S,K", J,P,S,K
    ans = []
    h1, h2, h3 = defaultdict(int), defaultdict(int), defaultdict(int)
    SS = range(1, S+1)
    
    #TT = [ SS[i:] + SS[:i] for i in range(S) ]
    #TTT = cycle(TT)
    
    for j in range(1, J+1):
        TT = list(SS)
        for p in range(1, P+1):
            #if h1[(j,p)] == K:
            #    continue
            for s in TT:
                if h1[(j,p)] == K or h2[(j,s)] == K or h3[(p,s)]==K:
                    continue
                ans.append( "{0} {1} {2}".format(j,p,s) )
                h1[(j,p)] += 1
                h2[(j,s)] += 1
                h3[(p,s)] += 1
            TT = TT[1:] + [TT[0]]
        SS = SS[1:] + [SS[0]]
        #SS = [SS[-1]] + SS[:-1]
    
    #if len(ans) != J*P*min(S,K):
    #    print "abcde"
    #print ans
    #pprint.pprint(dict(h1))
    #pprint.pprint(dict(h2))
    #pprint.pprint(dict(h3))
    #print pprint.pprint(h1), h2, h3
    #for j, p, s in product( range(1,J+1), range(1,P+1), range(1,K+1) ):
    #    if h1[(j,p)] == K or h2[(p] == :
    #        continue
    #    h1.add( (j,s) )
    #    h2.add( (p,s) )
    #    ans.append( "{0} {1} {2}".format(j,p,s) )
    return "{0}\n{1}".format( len(ans), "\n".join(ans) )
    

def main():
    f = open( sys.argv[1] ) if len(sys.argv)>=2 else sys.stdin
    #f = sys.stdin
    T = int(f.next())
    for case in range(1,T+1):
        #N = int( f.next().strip() )
        J, P, S, K = map( int, f.next().strip().split() )
        print "Case #{0}: {1}".format( case, solve(J,P,S,K) )
        

if __name__ == "__main__":
    main()
