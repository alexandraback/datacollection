#!/usr/bin/python

import sys
from math import *
from collections import *


def line():
    return sys.stdin.readline()


def solve(graph):
    #print graph
    for n in graph:
        #print n
        visit = [False for x in graph]

        d = deque()
        d.append(n)
        while d:
            cur = d.popleft()
            #print cur
            for c in cur[1]:
                #print "C", c
                if visit[c]:
                    return "Yes"
                visit[c] = True
                d.append(graph[c])
        #print visit
    return "No"

# def visit(n, graph):
#     if n.visited:
#         return True


tc = int(line())
for i in range(1, tc+1):
    
    nclasses = int(line())
    graph = []
    for j in range(nclasses):
        ints = [int(t)-1 for t in line().split()[1:]]
        graph.append((j,ints))


    print "Case #%s: %s" % (i, solve(graph))
