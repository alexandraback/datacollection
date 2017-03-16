#!/usr/bin/python

import sys

def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths

cases = int(sys.stdin.readline())
for case in range(1,cases+1):
    N = int(sys.stdin.readline().rstrip())
    gr = []
    gr2 = []
    gr.append([])
    for i in range(1,N+1):
        inh = map(int,sys.stdin.readline().rstrip().split(' '))
        inh.remove(inh[0])
        gr.append(inh)
        for j in inh:
            while len(gr2)<=j:
                gr2.append([])
            if gr2[j]:
                gr2[j].append(i)
            else:
                gr2[j] = [i]
    p = []
    for h in range(1,len(gr2)):
        g = gr2[h]
        if len(g)>1:
            for j in range(1,len(gr)):
                if j!=h:
                    p = find_all_paths(gr,j,h)
                    if len(p)>=2:
                        break
                if len(p)>=2:
                    break
            if len(p)>=2:
                break
    w="No"
    if len(p)>=2:
        w="Yes"
    print "Case #"+str(case)+": "+str(w)
