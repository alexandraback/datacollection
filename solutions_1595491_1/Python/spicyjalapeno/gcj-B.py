from collections import defaultdict
import sys

def one_max(n):
    return (n + 2) / 3

def two_max(n):
    return (n + 4) / 3 if n >= 2 else 0

t = int(sys.stdin.readline())
for i in xrange(t):
    ns = [int(s) for s in sys.stdin.readline().split()]
    n, s, p, ts = ns[0], ns[1], ns[2], ns[3:]
    ct = 0
    for su in sorted(ts, reverse=True):
        if one_max(su) >= p:
            ct += 1
        elif s and two_max(su) >= p:
            s -= 1
            ct += 1
    print "Case #%d: %d" % (i + 1, ct)