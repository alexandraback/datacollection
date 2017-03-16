from collections import defaultdict
import sys


maxn = 100000 # 2 * 1000 * 1000 + 7
d = [None] * (maxn)
def minr(s):
    s = str(s)
    m = s
    for i in xrange(len(s)):
        m = min(m, s[i:] + s[:i])
    m = int(m)
    for i in xrange(len(s)):
        n = int(s[i:] + s[:i])
        if n < maxn and s[i] != '0':
            d[n] = m
    return m


for i in xrange(maxn):
    if d[i] is None:
        d[i] = minr(i)
# print d
# exit(1)

t = int(sys.stdin.readline())
for i in xrange(t):
    a, b = [int(s) for s in sys.stdin.readline().split()]
    rc = defaultdict(int)
    for j in xrange(a, b+1):
        rc[d[j]] += 1
    ct = sum(i * (i - 1) / 2 for i in rc.values())
    print "Case #%d: %d" % (i + 1, ct)
