#!/usr/bin/env python

import sys
from collections import deque

def Solve(no):
    # le o numero de classes
    nodeCount = int(sys.stdin.readline())
    nodes = [0] * (nodeCount+1)
    inDegree = [0] * (nodeCount+1)
    outDegree = [0] * (nodeCount+1)
    inherits = [[]] * (nodeCount+1)
    visited = [False] * (nodeCount+1)
    # le as dependencias
    for each in range(1, nodeCount+1):
        values = map(int, sys.stdin.readline().split())
        start = each
        inherits[start] = []
        for dest in values[1:]:
            outDegree[start] += 1
            inDegree[dest] += 1
            inherits[start].append(dest)
    # procura os possiveis candidatos
    sources = []
    sinks = []
    for (indx, count) in enumerate(outDegree):
        if count>1: sources.append(indx)
    for (indx, count) in enumerate(inDegree):
        if count>1: sinks.append(indx)
    # atalho
    if (len(sources) == 0) or (len(sinks) == 0):
        return False
    # a partir de cada origem incrementa todas as classes atingidas
    for origin in sources:
        marks = [0] * (nodeCount+1)
        queue = deque()
        queue.append(origin)
        while True:
            try:
                each = queue.popleft()
                for other in inherits[each]:
                    queue.append(other)
                    marks[other] += 1
                    if marks[other] > 1:
                        #print "atingivel:", other, marks[other]
                        return True
            except IndexError:
                break
    return False

T = int(sys.stdin.readline())
for no in range(1, T+1):
    if Solve(no):
        ans = 'Yes'
    else:
        ans = 'No'
    print "Case #%d:" % (no,), ans

