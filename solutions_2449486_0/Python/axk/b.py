#!/usr/bin/env python

def calc(a, m, n):
    row_max = [max(a[i]) for i in xrange(m)]
    col_max = [max(a[i][j] for i in xrange(m)) for j in xrange(n)]
    if all(a[i][j] >= row_max[i] or a[i][j] >= col_max[j] for i in xrange(m) for j in xrange(n)):
        return 'YES'
    else:
        return 'NO'

T = input()
for t in xrange(T):
    m, n = (int(s) for s in raw_input().split())
    a = []
    for i in xrange(m):
        a.append([int(s) for s in raw_input().split()])
        assert len(a[-1]) == n
    print 'Case #%d: %s' % (t + 1, calc(a, m, n))
