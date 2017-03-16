from heapq import *
for T in xrange(input()):
    N,M = map(int,raw_input().split())
    Z = [raw_input() for _ in xrange(N)]
    E = [map(int,raw_input().split()) for _ in xrange(M)]
    A = [[] for _ in xrange(N)]
    E = [(i-1,j-1) for i,j in E]
    for i,j in E:
        A[i].append(j)
        A[j].append(i)
    for i in xrange(N):
        A[i].sort()
    m = min(range(N),key=lambda k: Z[k])
    v = [0]*N
    x = []
    b = []
    def min_next(r):
        x.append(Z[r])
        v[r] = 1
        for i in A[r]:
            if not v[i]:
                heappush(b,(Z[i],i))
        for i in A[r]:
            if not v[i]:
                while v[b[0][1]]: heappop(b)
                if Z[i]<=b[0][0] or sum(v[j] for j in A[i])==1:
                    min_next(i)
    min_next(m)
    print "Case #%d: %s"%(T+1,''.join(x))
