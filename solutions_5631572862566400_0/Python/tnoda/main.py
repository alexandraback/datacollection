def solve():
    N = input()
    F = [None] + map(int, raw_input().split())
    G = [[] for i in range(11)]
    for u in range(1, N+1):
        v = F[u]
        G[v].append(u)
        G[u].append(v)
        
    def dfs(depth, current, visited):
        visited[current] = True
        friends = [x for x in G[current] if not visited[x]]
        if len(friends) < 1:
            return depth
        z = max(dfs(depth + 1, u, visited) for u in friends)
        visited[current] = False
        return z

    visited = [False] * 11
    return max(dfs(1, u, visited) for u in range(1, N+1))
    

T = input()
for i in range(1, T+1):
    ans = solve()
    print('Case #%d: %d' % (i, ans))
 

