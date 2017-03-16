import sys
from math import sqrt, floor

T = int(sys.stdin.readline())

for t in range(T):
    C, D, V = [int(x) for x in sys.stdin.readline().split()]
    denoms = [int(x) for x in sys.stdin.readline().strip().split()]

    cant = []
    for j in range(1,V+1):
        # can we make i?
        d = len(denoms) - 1
        c = 0
        i = j
        while(i>0):
            if(i>=denoms[d]):
                i -= denoms[d]
                c += 1
            if(c == C) or (i < denoms[d]):
                d -= 1
                c = 0
            if(d<0) and not (i==0):
                denoms.insert(0,j)
                break

    print "Case #%d: %d"%(t+1,len(denoms) - D)



