T = int(raw_input())
for t in xrange(1, T + 1):

    x0, y0 = map(int, raw_input().split())

    path = ''
    if x0 > 0:
        path += x0 * 'WE'
    elif x0 < 0:
        path += (-x0) * 'EW'
    if y0 > 0:
        path += y0 * 'SN'
    elif y0 < 0:
        path += (-y0) * 'NS'

    print 'Case #{0}: {1}'.format(t, path)
