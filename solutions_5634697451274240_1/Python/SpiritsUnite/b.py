T = int(raw_input())
for C in xrange(1, T+1):
    s = raw_input() + "+"
    ans = 0
    for i in xrange(1, len(s)):
        if s[i] != s[i-1]: ans += 1
    print "Case #%d: %d" % (C, ans)
