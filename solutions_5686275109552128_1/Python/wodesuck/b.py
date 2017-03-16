dat = int(raw_input())
for cas in xrange(1, dat + 1):
    n = int(raw_input())
    p = map(int, raw_input().split())
    mx = max(p)
    ans = mx
    for i in xrange(1, mx):
        tt = i + sum([(x - 1) / i for x in p])
        ans = min(ans, tt)
    print "Case #%d: %d" % (cas, ans)
