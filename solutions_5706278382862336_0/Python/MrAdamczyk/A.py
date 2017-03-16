import sys

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

def solve(x):
    P, Q = (int(a) for a in raw_input().split('/'))
    _gcd = gcd(P, Q)
    P, Q = P/_gcd, Q/_gcd

    QQ = Q
    while QQ != 1:
        if QQ % 2 != 0:
            print "Case #%d: impossible" % x
            return
        QQ /= 2

    step = 0
    while P < Q:
        Q /= 2
        step += 1

    print "Case #%d: %d" % (x, step)

sys.setrecursionlimit(150000000)
T = int(raw_input())
for i in xrange(T):
    solve(i+1)
