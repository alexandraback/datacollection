T = int(raw_input())
for C in xrange(1, T+1):
    r, c, w = map(int, raw_input().strip().split())
    ans = (r - 1) * (c / w) + (c / w) - 1
    l = w + c % w
    ans += min(l, w+1)
    print "Case #%d: %d" % (C, ans)
