import sys


def solve(b, m):
    if 2**(b-2) < m:
        print "IMPOSSIBLE"
        return

    print "POSSIBLE"

    base2 = [1]
    n = 1
    while len(base2) < b-1:
        base2.append(n)
        n *= 2

    tot = m
    ids = []
    for i, k in reversed(list(enumerate(base2))):
        if tot >= k:
            tot -= k
            ids.append(i)

    gs = []
    for i in range(b):
        g = [0] * (i+1) + [1] * (b-i-1)
        g[b-1] = 0
        gs.append(g)

    for i in ids:
        gs[i][-1] = 1

    for g in gs:
        print ''.join(map(str, g))


N = int(sys.stdin.readline())
for i in range(N):
    b, m = map(int, sys.stdin.readline().split())
    print "Case #{}:".format(i+1),
    solve(b, m)
