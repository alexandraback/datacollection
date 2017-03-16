T = int(raw_input())
for i in xrange(0, T):
    n = int(raw_input())
    d = {}
    for a in xrange(1, 1000001):
        c = n * a
        for ch in str(c):
            d[ch] = 1
        if len(d) == 10:
            print 'Case #%s: %s' % (i + 1, c)
            break
    if a == 1000000:
        print 'Case #%s: INSOMNIA' % (i + 1)
