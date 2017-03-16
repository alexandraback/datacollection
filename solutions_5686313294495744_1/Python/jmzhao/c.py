# -*- coding: utf-8 -*-
"""
@author: jmzhao
GCJ 2016 Round 1
"""

import sys

class IO :
    def get(reader=str) :
        return reader(input().strip())
    def gets(reader=str, delim=None) :
        return [reader(x) for x in input().strip().split(delim)]
    def tostr(raw, writer=str, delim=' ') :
        return delim.join(writer(x) for x in raw)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    pass


def hungarian(G, edges, num_left) : 
    matching = [-1 for _ in G]
    def dfs(u) :
        for i in G[u] : # 对 u 的每个邻接点
            v = edges[i][1];
            if (not check[v]) :     # 要求不在交替路中
                check[v] = True; # 放入交替路
                if (matching[v] == -1 or dfs(matching[v])) :
                    # 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
                    matching[v] = u;
                    matching[u] = v;
                    return True;
        return False; # 不存在增广路，返回失败
    ans = 0;
    for u in range(num_left) :
        if (matching[u] == -1) :
            check = [False for _ in G]
            if (dfs(u)) :
                ans += 1;
    return ans;


def once():
    '''to cope once'''
    n = IO.get(int)
    l = [IO.gets() for _ in range(n)]
    left = list(set(p[0] for p in l))
    right = list(set(p[1] for p in l))
    
    num_left = len(left); num_right = len(right)
    edges = [(left.index(p[0]), num_left+right.index(p[1])) for p in l]
    G = [list() for _ in range(num_left+num_right)]
    for i, (u,v) in enumerate(edges) :
        G[u].append(i)
        G[v].append(i)
        
    h = hungarian(G, edges, num_left)
    
    return len(l) - (num_left + num_right - h)

def show(ans) :
    return ans #IO.tostr(ans, writer=str, delim=' ')
    
def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, show(ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework done with", msg, file=sys.stderr)
    main()
