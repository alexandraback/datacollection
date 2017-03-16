import sys
from itertools import izip
rl = lambda: sys.stdin.readline().strip()


def is_bigger_than(a, b):
    return all([_a > _b for _a, _b in izip(a, b)])


T = int(rl())
for tcase in range(T):
    N = int(rl())
    ss = [map(int, rl().split()) for i in range(N * 2 - 1)]
    cnts = {}
    for s in ss:
        for n in s:
            cnts[n] = cnts.get(n, 0) + 1
    rets = sorted(cnts.items(), key=lambda x: x[0], reverse=False)
    ans = []
    for r in rets:
        if r[1] & 1:
            ans.append(r[0])
    print >> sys.stderr, ss
    assert (len(ss) + 1) == len(ans) * 2
    print 'Case #%d: %s' % (tcase + 1, ' '.join(map(str, ans)))
