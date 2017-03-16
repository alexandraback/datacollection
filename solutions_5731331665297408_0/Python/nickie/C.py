#!/usr/bin/env python3

def solve(N, L, adj):
    u = min(zip(L, range(N)))[1]
    def bf(path, order):
        if not path:
            return "".join(L[v] for v in order) if len(order) == N else "BIG"
        u = path[-1]
        vs = sorted([(L[v], v) for v in adj[u] if v not in order])
        if vs:
            v = vs[0][1]
            return min(bf(path + [v], order + [v]), bf(path[:-1], order))
        else:
            return bf(path[:-1], order)
    return "".join(bf([u], [u]))

tests = int(input())
for test in range(tests):
    N, M = map(int, input().split())
    L = []
    for i in range(N):
        L.append(input().strip())
    adj = list([] for i in range(N))
    for i in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append(v)
        adj[v].append(u)
    result = solve(N, L, adj)
    print("Case #{}: {}".format(1+test, result))
