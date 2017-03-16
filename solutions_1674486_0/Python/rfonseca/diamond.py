#!/usr/bin/env python3

import sys

def dfs(visited, classes, node):
    if visited[node]:
        return True
    visited[node] = True
    for child in classes[node]:
        res = dfs(visited, classes, child)
        if res:
            return True
    return False

def diamond(n, classes):
    for i in range(n):
        visited = [False for _ in range(n)]
        exists = dfs(visited, classes, i)
        if exists:
            return "Yes"
    return "No"

if __name__ == "__main__":
    ncases = int(sys.stdin.readline().strip())
    for case in range(1, ncases + 1):
        n = int(sys.stdin.readline().strip())
        classes = []
        for i in range(n):
            line = sys.stdin.readline().strip().split(' ')
            #n = int(line[0])
            classes.append([(int(x) - 1) for x in line[1:]])
        print("Case #", case, ": ", diamond(n, classes), sep="")
