t = input()
for cas in xrange(t):
    a, b, k = map(int, raw_input().split())
    res = len(filter(lambda z: z<k, [x&y for x in xrange(a) for y in xrange(b)]))
    print 'Case #{0}: {1}'.format(cas+1, res)
