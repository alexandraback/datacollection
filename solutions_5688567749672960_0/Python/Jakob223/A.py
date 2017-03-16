from collections import defaultdict
from heapq import *
 
def dijkstra(f, t): 
    q, seen = [(0,f)], set()
    while q:
        (cost,v1) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            # path = (v1,)+ path
            if v1 == t: return cost
 
            for v2 in (v1+1,int(str(v1)[-1::-1])):
                if v2 not in seen:
                    heappush(q, (cost+1, v2))
 
    return float("inf")
 
for i,Ns in enumerate(open('A-small.txt').read().split('\n')):
 if i:
    N = int(Ns)
    print "Case #%d:" % (i),dijkstra(1,N)+1