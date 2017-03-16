tt = int(raw_input())
for t in xrange(1, tt+1):
    s = raw_input().strip()
    ans = 1 if s[-1] == '-' else 0
    for i in xrange(1, len(s)):
        if s[i] != s[i-1]:
            ans += 1
    print 'Case #%d: %s' % (t, ans)