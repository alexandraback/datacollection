#!/usr/bin/env python


def get_input(func):
    raw = raw_input().split(' ')
    return map(func, raw)


def dfs(node, ls, mark, visited):
    if mark[node - 1]:
        return True
    if visited[node - 1]:
        return False
    visited[node - 1] = True
    mark[node - 1] = True
    for i in ls[node - 1]:
        r = dfs(i, ls, mark, visited)
        if r:
            return True
    return False


def compute(mm):
    n = int(raw_input())
    ls = []
    visited = [False] * n
    for i in range(n):
        tmp = get_input(int)
        ls.append(tmp[1:])
    for i in range(1, n + 1):
        if visited[i - 1]:
            continue
        mark = [False] * n
        visited2 = [False] * n
        r = dfs(i, ls, mark, visited2)
        if r:
            print "Case #%d: Yes" % mm
            return
        visited = [x or y for x, y in zip(visited, visited2)]
    print "Case #%d: No" % mm


if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(100000)
    i = int(raw_input())
    for x in xrange(i):
        compute(x + 1)
