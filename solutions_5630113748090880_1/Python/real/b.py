import sys, itertools
from collections import defaultdict
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input


T = read_int()
for ca in range(1, T + 1):
    n  = read_int()

    c = defaultdict(int)
    for _ in xrange(2 * n - 1):
        for x in read_ints():
            c[x] += 1

    ans = []
    for k, v in c.iteritems():
        if v % 2:
            ans.append(k)

    ans = ' '.join(map(str, sorted(ans)))
    print 'Case #%d: %s' % (ca, ans)
