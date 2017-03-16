from sys import stdin
import sys
sys.setrecursionlimit(10000)

def dfs(i, j):
    #print 'dfs', i, j
    ret = 1
    for k in rg[i]:
        if k != j:
            ret = max(ret, 1 + dfs(k, i))
    return ret

def find_circle(i):
    #print 'search circle', i
    j = g[i]
    if depth[j] >= 0:
        size = depth[i] + 1 - depth[j]
        #print 'find circle', j, 'size', size
        if size >= 3:
            ans[0] = max(ans[0], size)
        else:
            ans[1] += dfs(i, j) + dfs(j, i)
    elif depth[j] == -1:
        depth[j] = depth[i] + 1
        find_circle(j)
    depth[i] = -2


T = int(stdin.readline())
for case in xrange(1, T+1):
    N = int(stdin.readline())
    g = map(lambda x : int(x)-1, stdin.readline().split())
    #print g
    rg = [[] for i in xrange(N)]
    for i in xrange(N):
        rg[g[i]].append(i)

    ans = [0, 0]

    depth = [-1] * N        # -1 white, >= 0 grey, -2 black
    for i in xrange(N):
        if depth[i] == -1:
            depth[i] = 0
            find_circle(i)

    print 'Case #{}: {}'.format(case, max(ans))
