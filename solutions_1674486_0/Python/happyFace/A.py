import time
import math
from collections import *

def run():
    f = open('A-small.in', 'r')
    lines = f.readlines()
    f.close()
    data = [line.rstrip() for line in lines]
    cases = int(lines[0])
    caseCount = 1
    lineNum = 1

    g = open('Aanswers.txt', 'w')

    while caseCount <= cases:
        classes = int(data[lineNum])
        lineNum += 1
        info = []
        for i in range(classes):
            info.append(data[lineNum].split(' '))
            lineNum += 1
        g.write('Case #' + str(caseCount) + ': ' + str(solve(classes, info)) + '\n')
        caseCount += 1
    g.close()

def listToString(things):
    string = ''
    for thing in things:
        string = string + str(thing) + ' '
    return string[:-1]

def solve(classes, info):
    def BFS(thing):
        seen[thing] = True
        seenNow = {thing : True}
        q = deque()
        q.append(thing)

        while len(q) > 0:
            nextNode = q.popleft()
            for node in graph[nextNode]:
                if node in seenNow:
                    return True
                else:
                    seen[node] = True
                    seenNow[node] = True
                    q.append(node)
        return False
    
    graph = {}
    for i in range(classes):
        graph[i] = [int(k) - 1 for k in info[i][1:]]
    seen = {}

    for thing in range(classes):
        if not thing in seen:
            x = BFS(thing)
            if x:
                return 'Yes'
    return 'No'
    

















