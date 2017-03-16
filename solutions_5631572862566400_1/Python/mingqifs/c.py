import sys
sys.setrecursionlimit(1000000)

def dfs(x, dep):
    s[x] = True
    depth[x] = dep
    y = F[x]
    if depth[y]:
        if not s[y]:
            ans = 0
        else:
            ans = depth[x] - depth[y] + 1
    else:
        ans = dfs(y, dep + 1)
    s[x] = False
    return ans
def dfs2(x, y):
    ans = 0
    for i in iF[x]:
        if i != y:
            ans = max(ans, dfs2(i, y))
    return ans + 1

T = int(input())
for case in range(1, T + 1):
    N = int(input())
    F = [int(x) - 1 for x in input().strip().split()]
    iF = []
    for i in range(N):
        iF.append([])
    d = [0] * N
    depth = [0] * N
    s = [False] * N
    for i in range(N):
        d[F[i]] += 1
        iF[F[i]].append(i)
    ans1 = 0
    ans2 = 0
    for i in range(N):
        if d[i] == 0:
            ans1 = max(dfs(i, 1), ans1)

    for i in range(N):
        if depth[i] == 0:
            ans1 = max(dfs(i, 1), ans1)
    for i in range(N):
        if not s[i] and F[F[i]] == i:
            s[i] = True
            s[F[i]] = True
            ans2 += dfs2(i,F[i])
            ans2 += dfs2(F[i], i)
    print("Case #{0}: {1}".format(case, max(ans1, ans2)))
