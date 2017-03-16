data = iter(open('A-small-attempt0.in').read().splitlines())
cases = int(next(data))

for case in range(1, cases + 1):
    x = int(next(data))
    d = set()
    ans = "INSOMNIA"
    if x > 0:
        for i in xrange(x, 10**6, x):
            for c in str(i):
                d.add(c)
            if len(d) == 10:
                ans = i
                break
    ans = str(ans)
    print "Case #%d: %s" % (case, ans)
