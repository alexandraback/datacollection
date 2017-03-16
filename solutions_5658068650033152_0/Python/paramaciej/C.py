#!/usr/bin/env python3

T = int(input())

def wyp(N, M):
    return max(N-2,0)*max(M-2,0)

wyn = {}
def opt(N, M, K):
    if (N, M, K) in wyn:
        return wyn[(min(N,M), max(N,M), K)]
    ile = 1000**3
    if N*M >= K:
        ile = N*M - wyp(N,M)

    for i in range(1,5):
        if N*M - i >= K and N > 2 and M > 2:
            ile = N*M - wyp(N,M) - i
    if N*M > K:
        ile = min(ile, min(opt(N-1,M,K), opt(N,M-1,K)))
    wyn[(min(N,M),max(N,M),K)] = ile
    return ile


for t in range(1, T+1):
        N, M, K = [int(x) for x in input().split()]
        print("Case #{}: {}".format(t, opt(N, M, K)))
    
