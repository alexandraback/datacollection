t = int(raw_input())
for kei in xrange(t):
    d = int(raw_input())
    p = [int(x) for x in raw_input().split()]
    m = max(p)
    ans = 1000
    for i in xrange(1, m+1):
        tmp = 0
        q = list(p)
        for x in q:
            if x > i:
                tmp += (x + i - 1) / i - 1
        tmp += i
        ans = min(ans, tmp)
    print "Case #%d: %d" % (kei+1, ans)

