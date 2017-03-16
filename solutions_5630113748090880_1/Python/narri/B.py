import sys
from collections import defaultdict

def _cc():
    for line in sys.stdin:
        for x in line.strip().split():
            yield x

_cin = _cc()
cin = _cin.next


def solve(arr):
    dd = defaultdict(int)
    for z in arr:
        for k in z:
            dd[k] += 1
    keys = []
    for k in dd:
        if dd[k] % 2 != 0:
            keys.append(k)
    return ' '.join(str(i) for i in sorted(keys))


T = int(cin())
for cn in xrange(1,T+1):
    N = int(cin())
    arr = [[int(cin()) for i in xrange(N)] for j in xrange(2*N-1)]
    print "Case #%d: %s" % (cn, solve(arr))


