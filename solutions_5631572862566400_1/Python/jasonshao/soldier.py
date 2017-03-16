import sys
sys.setrecursionlimit(10000)

hack = 0
g_seen = set()

def cycle(id, bfs):
    count = 1
    cur = id
    while bfs[cur] != id:
        g_seen.add(cur)
        cur = bfs[cur]
        count += 1
    return count


def dfs(id, bfs, seen):
    if id in seen:
        return id
    seen.add(id)
    return dfs(bfs[id], bfs, seen)

def longe(id, adj, seen, forbid):
    if id == forbid:
        return 0
    count = 0
    for i in adj[id]:
        count = max(count, longe(i, adj, seen, forbid))
    return count + 1

t = input()
for poo in range(t):
    hack = 0
    g_seen = set()
    n = input()
    bfs = [-1] + map(int, raw_input().split())
    ans = 0
    for id in range(1, n + 1):
        rep = dfs(id, bfs, set())
        hack = max(cycle(rep, bfs), hack)

    invert = {}
    for i in range(1, n+1):
        if bfs[i] in invert:
            invert[bfs[i]].append(i)
        else:
            invert[bfs[i]] = [i]
    for i in range(1, n+1):
        if i not in invert:
            invert[i] = []
    
    poop = 0
    hack3 = set()
    for i in bfs[1:]:
        if i == bfs[bfs[i]]:
            if i in hack3:
                continue
            #couple
            a, b = i, bfs[i]
            hack3.add(a)
            hack3.add(b)
            long_a = longe(a, invert, {b}, b)
            long_b = longe(b, invert, {a}, a)
            poop += long_a + long_b
    hack = max(hack, poop)
    print "Case #" + str(poo + 1) + ": " + str(hack)
