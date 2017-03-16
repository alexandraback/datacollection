# -*- coding: utf-8 -*-

import sys
fin = sys.stdin
T = int(fin.readline())

l = {}
    
graph = {}


def find_all_paths(start, end, path=[]):
        cache_paths = cache.get((start,end)) 
         
        if not cache_paths is None:
            return cache_paths

        path = path + [start]
        if start == end:
            return [path]
        nodes = graph.get(start)
        if not nodes:
            return []
        paths = []
        for node in nodes:
            if node in path:
                continue
            
            newpaths = find_all_paths(node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
                
        return paths
    
def solve(case):           
    N = int(fin.readline())    
    for i in xrange(1,N+1):
        vals = map(int, fin.readline().split())
        graph[i] = vals[1:]
            
    for X in xrange(1,N+1):
        for Y in xrange(1,N+1):
            if X == Y:
                continue
            
            paths = find_all_paths(X, Y)
            
            cache[(X,Y)] = paths 
            if not paths:
                continue
            
            if len(paths) > 1:
                print "Case #%d: Yes" % case
                return 
    
    print "Case #%d: No" % case
            
for case in range(1,T+1):
    cache = {}
    solve(case)
        