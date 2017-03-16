from sys import stdin

t = int(stdin.readline())
for i in xrange(t):
    k, c, s = map(int, stdin.readline().split())
    mins = (k + c - 1) / c

    if s < mins:
        print 'Case #%d: IMPOSSIBLE' % (i+1)
        continue

    idx = []
    low_idx = 1
    while low_idx <= k:
        j = (low_idx - 1) * (k ** (c - 1)) + 1
        for e, ii in enumerate(xrange(low_idx + 1, min(low_idx + c, k + 1))):
            j += (ii - 1) * (k ** (c - 2 - e))
        idx.append(j)
        low_idx += c

    res = ''
    for ii in idx:
        res += ' %d' % ii
    print 'Case #%d:%s' % ((i+1), res)
