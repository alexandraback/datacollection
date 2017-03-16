import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input
INF = 2**60

for no_t in xrange(1, read_int() + 1):
    n = read_int()
    a = read_ints()
    ans = INF

    for x in xrange(1, 1001):
        tmp = sum((n + x - 1) / x - 1 for n in a) + x
        ans = min(ans, tmp)
    print 'Case #%d: %s' % (no_t, ans)
