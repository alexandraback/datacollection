from collections import Counter as C

def bfs(U, V, pair_U, pair_V, graph, dist):
    Q = []
    for u in U:
        if pair_U[u] == None:
            dist[u] = 0
            Q.append(u)
        else:
            dist[u] = 10 ** 20
    dist[None] = 10 ** 20
    while Q:
        u = Q.pop(0)
        if dist[u] < dist[None]:
            for v in graph[u]:
                if dist[pair_V[v]] == 10 ** 20:
                    dist[pair_V[v]] = dist[u] + 1
                    Q.append(pair_V[v])
    return dist[None] != 10 ** 20

def dfs(U, V, pair_U, pair_V, graph, dist, u):
    if u:
        for v in graph[u]:
            if dist[pair_V[v]] == dist[u] + 1:
                if dfs(U, V, pair_U, pair_V, graph, dist, pair_V[v]):
                    pair_V[v] = u
                    pair_U[u] = v
                    return True
        dist[u] = 10 ** 20
        return False
    return True

def hopcroft_karp(U, V, graph):
    pair_U = {u: None for u in U}
    pair_V = {v: None for v in V}
    dist = {}
    matchings = 0
    while bfs(U, V, pair_U, pair_V, graph, dist):
        for u in U:
            if pair_U[u] == None:
                if dfs(U, V, pair_U, pair_V, graph, dist, u):
                    matchings += 1
    total = 0
    for u in pair_U:
        if not pair_U[u]:
            matchings += 1
    for v in pair_V:
        if not pair_V[v]:
            matchings += 1
    return matchings

def make_graph(edges):
    graph = {}
    for u, v in edges:
        graph.setdefault((u, 0), set())
        graph.setdefault((v, 1), set())
        graph[(u, 0)].add((v, 1))
        graph[(v, 1)].add((u, 0))
    return graph

def solve(n, tuples, first, second):
    graph, A, B = make_graph(tuples), first, second
    return n - hopcroft_karp(A, B, graph)

def main():
    for _ in range(int(input())):
        first, second, tuples = [], [], []
        n = int(input())
        for i in range(n):
            x, y = tuple(input().split())
            tuples.append((x, y))
            first.append((x, 0))
            second.append((y, 1))
        print('Case #%d: %d' % (_ + 1, solve(n, tuples, first, second)))

if __name__ == '__main__':
    main()
