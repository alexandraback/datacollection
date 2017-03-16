T = int(raw_input())
for cs in xrange(0, T):
    k, c, s = [int(ss) for ss in raw_input().split()]
    if c == 1 and s < k:
        print 'Case #%s: IMPOSSIBLE' % (cs + 1)
    elif 2 * s < k:
        print 'Case #%s: IMPOSSIBLE' % (cs + 1)
    else:
        mx = pow(k, c - 1)
        res = [(1 + i * mx) for i in xrange(0, s)]
        print 'Case #%s: %s' % (cs + 1, ' '.join([str(rs) for rs in res]))
