#!/usr/bin/env python
# -*- coding: utf-8 -*-

class UnionFind:
    def __init__(self, N):
        self.rank = [0]*N
        self.par = list(range(N))

    def find(self, x):
        if x != self.par[x]:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    
    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if(self.rank[x] > self.rank[y]):
            self.par[y] = x
        else:
            self.par[x] = y
        if(self.rank[x] == self.rank[y]):
            self.rank[y] += 1

import sys
sys.setrecursionlimit(10**2)

def dfs(s, n, visited, count):
    if n == s:
        return count
    if (1<<BFF[n]) & visited > 0:
        if BFF[BFF[n]] == n:
            # 自分をBFFとする最長辺の長さを返す
            ret = 0
            for u in R_BFF[n]:
                if u == BFF[n]: continue
                ret = max(ret, rev_dfs(u, 0) + 1)
            return count + 1 +  ret
        else:
            return 0
    return dfs(s, BFF[n], visited | (1<<n), count + 1)

def rev_dfs(s, count):
    if R_BFF[s] == []:
        return count
    ret = 0
    for n in R_BFF[s]:
        ret = max(ret, rev_dfs(n, count + 1))
    return ret

T = int(input())
for case in range(T):
    N = int(input())
    BFF = list(map(lambda x:int(x)-1,input().split()))
    R_BFF = [[] for i in range(N)]

    for i in range(N):
        R_BFF[BFF[i]].append(i)

    uf= UnionFind(N)
    for i in range(N):
        uf.unite(i, BFF[i])

    count = dict()
    for i in range(N):
        if uf.find(i) in count:
            count[uf.find(i)] = max(count[uf.find(i)], dfs(i, BFF[i], 0, 0))
        else:
            count[uf.find(i)] = dfs(i, BFF[i], 0, 0)
    ans = sum(count.values()) + len(count)
    print("Case #{0}: {1}".format(case+1, ans)) 
