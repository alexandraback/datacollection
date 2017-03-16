import sys

def solve():
    C, F, X = map(float, sys.stdin.readline().split())

    r = 2
    base = 0
    res = X / 2

    while True:
        res2 = base + C / r + X / (r + F)

        if res2 > res: break

        base += C / r
        r += F
        res = res2

    return res

T = int(sys.stdin.readline())
for t in xrange(T):
    print 'Case #%d: %.7f' % (t+1, solve())