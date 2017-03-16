class BoxedNumber:
    def __init__(self): self.n = 0

def dfs(bff, i, nbs, number, ans, active):
    nbs[i] = number.n
    number.n += 1
    active[i] = True
    if nbs[bff[i]] is not None:
        if active[bff[i]]:
            ans.n = max(ans.n, nbs[i] - nbs[bff[i]] + 1)
    else:
        dfs(bff, bff[i], nbs, number, ans, active)
    active[i] = False

def max_branch(i, ibff, p):
    m = 1
    for j in ibff[i]:
        m = max(m, m if j == p else 1 + max_branch(j, ibff, i))
    return m

T = int(input())

for tc in range(1, T+1):
    n = int(input())
    bffs = list(map(lambda x: int(x) - 1, input().split()))
    ibffs = list([list() for i in range(n)])
    for i, bff in enumerate(bffs):
        ibffs[bff].append(i)
    nb, ans = BoxedNumber(), BoxedNumber()
    active = list([False for x in range(n)])
    nbs = list([None for i in range(n)])
    for i in range(n):
        if nbs[i] is None:
            dfs(bffs, i, nbs, nb, ans, active)
    chain = 0
    for i in range(len(bffs)):
        if bffs[bffs[i]] == i:
            chain += max_branch(i, ibffs, bffs[i]) + max_branch(bffs[i], ibffs, i)
    print("Case #{}: {}".format(tc, max(chain // 2, ans.n)))
