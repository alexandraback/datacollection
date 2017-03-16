T = int(raw_input())
for c in xrange(T):
    r, t = map(int, raw_input().split())
    ans = 0
    while True:
        t -= (r + 1)**2 - r**2
        r += 2
        if t < 0: break
        ans += 1
    print "Case #%d: %d" % (c + 1, ans)

