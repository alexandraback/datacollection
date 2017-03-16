t = input()
for cas in xrange(t):
    e, r, n = map(int, raw_input().split())
    v = map(int, raw_input().split())
    print 'Case #{0}: {1}'.format(cas+1, sum(v)*r+(e-r)*max(v))

