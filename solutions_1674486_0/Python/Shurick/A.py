#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import sys
ifs = sys.stdin
ofs = sys.stdout


YES = 'Yes'
NO = 'No'


def dfs(G,v,visited):
    visited[v-1] = True
    #print ' :: ',v
    E = G[v]
    #print E
    for ve in E:
        if not visited[ve-1]:
            a = dfs(G,ve,visited)
            if a:
                return True
        else:
            #print 'visited:',ve
            return True
    return False


def solve(G):
    for v in G.keys():
        #print 'from vertex: ',v
        visited = [False]*len(G)
        a = dfs(G,v,visited)
        #print a
        if a:
            return YES
    return NO


def numbers_from_line(d=' '):
    return [int(s) for s in ifs.readline().strip().split(d) if len(s.strip())>0]


T = int(ifs.readline())
for t in range(1,T+1):
    N = int(ifs.readline())
    G = {}
    for v in range(1,N+1):
        A = numbers_from_line()
        M = A[0]
        E = A[1:]
        assert len(E) == M
        G[v] = set(E)
    #print G
    a = 'test'#solve(G)
    #if t==2:
    a = solve(G)
    ofs.write('Case #%d: %s\n' % (t,a))
