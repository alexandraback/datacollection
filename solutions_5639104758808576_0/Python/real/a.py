import sys, itertools, collections
sys.setrecursionlimit(10000)

read_ints = lambda: map(int, raw_input().split())
read_int  = input

for no_t in xrange(1, read_int() + 1):
    n, s = raw_input().split()
    ans, c = 0, 0
    for i, x in enumerate(s):
        while c < i:
            c += 1
            ans += 1
        c += (ord(x) - ord('0'))

    print 'Case #%d: %s' % (no_t, ans)
