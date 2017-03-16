from itertools import groupby, permutations
from multiprocessing import Pool
import sys


ri = lambda: int(raw_input())
rii = lambda: list(map(int, raw_input().split()))

MOD = int(1e9) + 7


def do(ps):
    s = ''.join(ps)
    prev_c = s[0]
    used = {prev_c}
    for c in s[1:]:
        if c == prev_c:
            continue
        else:
            if c in used:
                return 0
            else:
                used.add(c)
        prev_c = c
    return 1


def solve():
    res = 0
    _ = ri()
    ss = raw_input().split()
    ss[:] = [''.join([e for e, i in groupby(s)]) for s in ss]

    pss = [ps for ps in permutations(ss)]
    res += sum(pool.map(do, pss))
    res %= MOD
    print res


tt = ri()
pool = Pool()
for t in range(tt):
    print >> sys.stderr, t,
    print 'CASE #%s:' % (t + 1),
    solve()
