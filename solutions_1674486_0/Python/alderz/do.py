#!/usr/bin/env python
import sys

def read_number():
    return int(sys.stdin.readline())

def BFS(graph, start):
    queue = [start]
    flags = [False] * len(graph)
    flags[start] = True
    success = False
    while queue != [] and not success:
        curr = queue.pop()
        for dest in graph[curr]:
            if not flags[dest]:
                flags[dest] = True
                queue.append(dest)
            else:
                success = True
                break
    return success

format = "Case #%d: %s"
for case in range(1, read_number() + 1):
    graph = []
    for i in range(read_number()):
        targets = map(int, sys.stdin.readline().split())[1:]
        targets = map(lambda x: x - 1, targets)
        graph.append(targets)

    # BFS
    success = False
    for i in range(len(graph)):
        if BFS(graph, i):
            success = True
            break

    print(format % (case, "Yes" if success else "No"))
