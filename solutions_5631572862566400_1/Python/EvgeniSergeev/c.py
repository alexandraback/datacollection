
#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))

INF = 2147483647


import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)


def dfs(v, nexts, visited, nvisit, cycle):
    if visited[v] < nvisit:
        return
    elif visited[v] == nvisit:
        cycle.append(v)
        while nexts[cycle[-1]] != v:
            cycle.append(nexts[cycle[-1]])
        return
    visited[v] = nvisit
    dfs(nexts[v], nexts, visited, nvisit, cycle)


def maxdepth(v, avoid, prevs):
    rr = 0
    for p in prevs[v]:
        if p == avoid: continue
        rr = max(rr, 1 + maxdepth(p, avoid, prevs))
    return rr


T =        int( stdin.readline().strip() )
for icase in range(1, T+1):
    N =        int( stdin.readline().strip() )

    bffs = map(int, stdin.readline().strip().split())
    bffs = [k-1 for k in bffs]

    visited = [INF] * N

    bicycles = []
    othercycles = []
    for i in range(N):
        cycle = []
        dfs(i, bffs, visited, i, cycle)
        if len(cycle) == 0:
            continue
        elif len(cycle) == 2:
            bicycles.append(cycle)
        else:
            othercycles.append(cycle)

    prevs = [[] for i in range(N)]
    for i, nex in enumerate(bffs):
        prevs[nex].append(i)

    rr = 0
    for bic in bicycles:
        rr += 2 + maxdepth(bic[0], bic[1], prevs) + maxdepth(bic[1], 
                                                             bic[0], prevs)

    if len(othercycles) >= 1:
        rr = max(rr, max(len(oc) for oc in othercycles))

    print "Case #%d: %d" % (icase, rr)
