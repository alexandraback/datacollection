t = int(raw_input())
for kei in xrange(t):
    smax, s = raw_input().split()
    smax = int(smax)
    s = [int(x) for x in s]
    tot = 0
    ans = 0
    for i in xrange(smax+1):
        if s[i] > 0:
            while tot < i:
                tot += 1
                ans += 1
        tot += s[i]
    print "Case #%d: %d" % (kei+1, ans)