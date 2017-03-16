T = int(raw_input())
for i in xrange(0, T):
    p = raw_input()
    s = '-+'
    n = 0
    while p.count(s[0]) > 0:
        p = p[:p.rfind(s[0]) + 1]
        lidx = p.find(s[0])
        if lidx > 0:
            n += 1
            p = p[lidx:]
        p = p[::-1]
        s = s[::-1]
        n += 1

    print 'Case #%s: %s' % (i + 1, n)
