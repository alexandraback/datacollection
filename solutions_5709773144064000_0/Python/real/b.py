import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

read_floats = lambda: map(float, raw_input().split())

INF = 10**1000

for no_t in xrange(1, read_int() + 1):
    c, f, x = read_floats()

    ans = INF
    current, rate, now = 0, 2, 0
    while now < ans:
        # just wait
        wait = (x - current) / rate + now
        ans = min(ans, wait)
        # purchase
        now += (c - current) / rate
        rate += f

    print 'Case #%d: %.7f' % (no_t, ans)
