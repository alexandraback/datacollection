from random import random

def product(ns):
    ret =1
    for n in ns:
        ret*=n
    return ret

T = int(input())
print('Case #1:')
R,N,M,K = [int(x) for x in input().split()]

poss = [tuple(sorted([a,b,c])) for a in range(2,M+1) for b in range(2,M+1) for c in range(2,M+1)]
poss = list(set(poss))
poss.sort()

counts = {}

for (i,p) in enumerate(poss):
    for N in range(100000):
        res = 1
        for k in range(3):
            if random()>0.5:
                res*= p[k]
        if res not in counts:
            counts[res] = [0]*len(poss)
        counts[res][i]+=1

for r in range(R):
    ks = [int(x) for x in input().split()]
    for k in ks:
        if k not in counts:
            counts[k] = [0]*len(poss)
    chances = [(product([counts[k][i] for k in ks]),poss[i]) for i in range(len(poss))]
    ans = max(chances)[1]
    print(*ans,sep='')
        
            
            
