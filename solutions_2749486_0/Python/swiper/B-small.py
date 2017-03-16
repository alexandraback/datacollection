def mkpath(n, d):
    if n < 0:
        d = d[::-1]
    return d*abs(n)

def solve(X, Y):
    return mkpath(X, "WE") + mkpath(Y, "SN")

import sys
readline = sys.stdin.readline

T = int(readline())
for i in xrange(T):
    X, Y = map(int, readline().strip().split())
    print "Case #%d: %s" % (i+1, solve(X, Y))
