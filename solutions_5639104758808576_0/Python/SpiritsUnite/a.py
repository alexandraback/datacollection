T = int(raw_input())
for i in xrange(T):
    _, s = raw_input().split()
    st, ans = 0, 0
    for at, amt in enumerate(s):
        amt = int(amt)
        if st < at:
            ans += at - st
        st = max(st, at) + amt
    print "Case #%d: %d" % (i+1, ans)
