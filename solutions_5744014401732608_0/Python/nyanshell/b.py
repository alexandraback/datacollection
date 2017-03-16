from collections import defaultdict

def rootf(dp, p, i):
    while True:
        if p == i: return True
        if dp[p] == p:
            return False
        p = dp[p]


def sol():
    n, m = [int(x) for x in input().split()]
    pset = [set() for i in range(n)]
    dp = [i for i in range(n)]
    dp[0] = -1
    ind = [0 for _ in range(n)]
    ind[0] = 1
    outd = [0 for _ in range(n)]
    outd[n-1] = 1
    p = 0
    w = 0
    e = set()
    while p > -1:
        updated = False
        for i in range(1, n):
            if i != p and i not in pset[p] and (p, i) not in e:
                inc = ind[p] * outd[i]
                # print(p, i, inc, dp)
                if w + inc <= m:
                    dp[i] = p
                    # pset[i].update(pset[p])
                    pset[i].add(p)
                    e.add((p, i))
                    ind[i] += 1
                    outd[p] += 1
                    # print('i->p', i, p, inc, w + inc)
                    p = i
                    if p == n - 1:
                        p = dp[p]
                    w = w + inc
                    updated = True
                    break
        if not updated:
            # print('p->dp', p, dp[p])
            # p = dp[p]
            p = p - 1
            # input()
    if m == w:
        ans = ''
        for i in range(n):
            for j in range(n):
                if (i, j) in e:
                    ans += '1'
                else:
                    ans += '0'
            if i != n - 1: ans += '\n'
        # print(ans)
        return 'POSSIBLE\n' + ans
    else:
        return 'IMPOSSIBLE'


t = int(input())
for i in range(t):
    print("Case #%s: %s" % (i+1, sol()))
