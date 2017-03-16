#!/usr/bin/python -SOO
from itertools import combinations,chain
from collections import Counter
class Chest:
    def __init__(self,t,ks):
        self.t,self.ks = t,ks
sol = []
def dfs(l,s,n,cs,ks):
    global sol
    #print(l,ks)
    if l>=n:
        return True
    for k,c in ks.items():
        xs = [i+1 for i in range(n) if i+1 not in s and cs[i].t==k]
        for y in combinations(xs,c):
            sol[l:l+len(y)] = y
            z = Counter()
            z[k] = c
            if dfs(l+c,set(sol),n,cs,ks-z+Counter(chain.from_iterable(cs[i-1].ks for i in y))):
                   return True
    return False
for case in range(1,int(input())+1):
    k,n = map(int,input().strip().split())
    ks = Counter(map(int,input().strip().split()))
    cs = [(lambda xs:Chest(xs[0],xs[2:]))(list(map(int,input().strip().split())))for _ in range(n)]
    sol=[0]*n
    print('Case #{}: {}'.format(case,' '.join(map(str,sol)) if dfs(0,set(),n,cs,ks) else 'IMPOSSIBLE'))
