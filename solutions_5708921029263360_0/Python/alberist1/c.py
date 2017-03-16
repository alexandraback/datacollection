#!/usr/bin/python3
# -*- coding: utf-8 -*-


def solve():
    j, p, s, k = map(int, input().split())
    res = []
    p1 = {}
    p2 = {}
    p3 = {}
    for x1 in range(1, j+1):
        for x2 in range(1, p+1):
            for x3 in range(1, s+1):
                d1 = (x1, x2)
                d2 = (x1, x3)
                d3 = (x2, x3)
                if p1.get(d1, 0) >= k or p2.get(d2, 0) >= k or p3.get(d3, 0) >= k:
                    continue
                p1[d1] = p1.get(d1, 0) + 1
                p2[d2] = p2.get(d2, 0) + 1
                p3[d3] = p3.get(d3, 0) + 1
                res.append('%d %d %d' % (x1, x2, x3))
    res2 = solve2(j, p, s, k)
    if len(res) != len(res2):
        print (j, p, s, k, res, res2)
    return '\n'.join([str(len(res))] + res)


p1 = [[0 for _ in range(11)] for _ in range(11)]
p2 = [[0 for _ in range(11)] for _ in range(11)]
p3 = [[0 for _ in range(11)] for _ in range(11)]
cur = []

def solve():
    j, p, s, k = map(int, input().split())
    res = solve2(j, p, s, k)
    return '\n'.join([str(len(res))] + ['%d %d %d' % x for x in res])

def solve2(j, p, s, k):
    global u, values, best
    values = [(x1, x2, x3) for x1 in range(1, j+1) for x2 in range(1, p+1) for x3 in range(1, s+1)]
    u = [False for _ in values]
    best = []
    dfs(k)
    return best

def dfs(k, i=0):
    if len(cur) > len(best):
        best[:] = cur
    for t in range(i, len(values)):
        x1, x2, x3 = values[t]
        if u[t] or p1[x1][x2] >= k or p2[x1][x3] >= k or p3[x2][x3] >= k:
            continue
        u[t] = True
        cur.append(values[t])
        p1[x1][x2] += 1
        p2[x1][x3] += 1
        p3[x2][x3] += 1
        dfs(k, t+1)
        p1[x1][x2] -= 1
        p2[x1][x3] -= 1
        p3[x2][x3] -= 1
        cur.pop()
        u[t] = False


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print('Case #%d:' % (i+1), solve())
