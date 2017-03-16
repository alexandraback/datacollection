#! /usr/bin/python
# kmwho
# CodeJam 2016  1A

from __future__ import print_function

def dfs(c,F,dep, curdepth=1, chain=None):
    if not chain:
        chain = []
    
    chain.append(c)
    if dep[c] != 0:
        #print( "Found a circle!", c, dep[c], curdepth, curdepth-dep[c] )
        res = {
                "depth" : curdepth - 1,
                "cyclesize" : curdepth - dep[c],
                "chain" : chain,
                "entry" : c,
                "tail"  : dep[c]-1
            }
        return res
    dep[c] = curdepth
    return dfs(F[c], F, dep, curdepth+1, chain)


def solvecase():
    N = int(input())
    F = [ c-1 for c in map(int, input().strip().split()) ]
    countF     = { c: F.count(c) for c in range(N) }
    specialC   = set( c for c in range(N) if F[F[c]] == c )
    vis        = { c:False for c in range(N) }
    chainentry = {}
    chains     = {}
    maxR  = 0
    for c in range(N):
        dep = { i:0 for i in range(N) }
        if countF[c] == 0:
            res = dfs(c, F, dep, 1, [])
            entry = res["entry"]
            chain = res["chain"]
            if not entry in chainentry:
                chainentry[entry] = []
            chains[c] = { "tail" : res["tail"], "length":len(chain)-1, "entry" : entry, "exit" : chain[-2], "cycle" : res["cyclesize"] }
            chainentry[entry].append( c )
            for node in chain:
                vis[node] = True
    for c in range(N):
        if not vis[c]:
            dep  = { i:0 for i in range(N) }
            res  = dfs(c,F,dep,1,[])
            maxR = max(maxR, res["cyclesize"])
    
    for start,chain in chains.items():
        length = chain["cycle"]
        if chain["cycle"] == 2:
            tlens = [0,0]
            if chain["exit"] in chainentry:
                tlens.extend( chains[e]["tail"] for e in chainentry[chain["exit"]] )
            length += chain["tail"]
            tlens.sort()
            length += tlens[-1]
        maxR = max(maxR, length)
    return maxR

def solve():
    T  = int(input())
    for t in range(1,T+1):
        res = solvecase()
        print( "Case #" + str(t) + ": " + str(res) )

def main():
    solve()


main()
