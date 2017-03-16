T = int(raw_input())

def solve(start, k, c):
    res = start % k
    for i in xrange(1, c):
        start = (start + 1) % k
        res = (start + res * k)
    return res + 1

for cs in xrange(0, T):
    k, c, s = [int(ss) for ss in raw_input().split()]
    if k > c * s:
        print 'Case #%s: IMPOSSIBLE' % (cs + 1)
    else:
        res = [solve(start * c, k, c) for start in xrange(0, (k + c - 1) / c)]
        print 'Case #%s: %s' % (cs + 1, ' '.join([str(rs) for rs in res]))
