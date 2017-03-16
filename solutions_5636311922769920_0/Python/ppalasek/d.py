t = int(raw_input())

for tt in xrange(t):
    k, c, s = map(int, raw_input().split())

    print 'Case #%d:' % (tt + 1), 
    for i in xrange(s):
        r = 0
        p = c - 1

        while (p >= 0):
            r += i * k ** p
            p -= 1

        print r + 1,
    print