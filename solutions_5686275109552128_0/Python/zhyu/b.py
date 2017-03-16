from functools import reduce
t = int(raw_input())
for cas in xrange(t):
    d = int(raw_input())
    p = map(int, raw_input().split())
    res = p_max = max(p)
    for limit in xrange(1, p_max):
        res = min(
            res,
            reduce(lambda x, y: x + (y - 1) / limit,
                   filter(lambda x: x > limit, p), limit
                   )
            )
    print 'Case #{0}: {1}'.format(cas+1, res)
