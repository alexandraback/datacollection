for i in xrange(int(raw_input().strip())):
    s = map(int, list(raw_input().strip().split()[1]))
    n = sum(s)
    l, r = -1, 1001
    while l + 1 < r:
        m = (l + r) / 2
        p = m
        for j, k in enumerate(s):
            if k > 0 and p < j:
                l = m
                break
            p += k
        if l != m:
            r = m
    print "Case #%d: %d" % (i + 1, r)
