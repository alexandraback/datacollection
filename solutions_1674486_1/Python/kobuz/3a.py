import sys
sys.setrecursionlimit(1005)


def dfs(i):
    visited = [False] * n
    return dfs_visit(i, visited)


def dfs_visit(i, visited):
    visited[i] = True
    for parent in adj[i]:
        if visited[parent]:
            return True
        res = dfs_visit(parent, visited)
        if res:
            return True
    return False


tests = int(raw_input())
for i in xrange(1, tests + 1):
    n = int(raw_input())
    adj = [0] * n
    for j in xrange(n):
        line = map(int, raw_input().split())
        adj[j] = map(lambda x: x - 1, line[1:])
    res = False
    for j in xrange(n):
        res = dfs(j)
        if res:
            break
    if not res:
        ans = 'No'
    else:
        ans = 'Yes'
    print 'Case #%d: %s' % (i, ans)
