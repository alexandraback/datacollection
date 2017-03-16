from collections import *

def solve(xs):
    H,W=len(xs),len(xs[0])
    hs = defaultdict(set)
    for i,r in enumerate(xs):
        for j,h in enumerate(r):
            hs[h].add((i,j))
    for h in sorted(hs):
        while hs[h]:
            i,j = hs[h].pop()
            if all(xs[i][k] <= h for k in range(W)):
                hs[h]-=set((i,k) for k in range(W))
            elif all(xs[k][j] <= h for k in range(H)):
                hs[h]-=set((k,j) for k in range(H))
            else:
                return 'NO'
    return 'YES'
            
rd = raw_input
for t in range(1,1+int(rd())):
    h,w=map(int,rd().split())
    print 'Case #%d: %s' % (t,solve([map(int,rd().split()) for _ in range(h)]))
