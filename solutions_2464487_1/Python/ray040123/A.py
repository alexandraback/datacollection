import math

def solve(r, t):
    nL, nR = 0, t
    while nL + 1 < nR:
        n = (nL + nR) // 2
        if n * (2 * n + 2 * r - 1) <= t:
            nL = n
        else:
            nR = n
    return nL

T = int(raw_input())
for i in xrange(T):
    r, t = map(int, raw_input().split())
    n = solve(r, t)
    print 'Case #{}: {}'.format(i + 1, n)
