dat = int(raw_input())
for cas in xrange(1, dat + 1):
    _, s = raw_input().split()
    s = map(int, s)
    ans = 0
    tot = 0
    for i, x in enumerate(s):
        ans = max(ans, i - tot)
        tot += x
    print "Case #%d: %d" % (cas, ans)
