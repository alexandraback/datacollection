t = input()

for tc in range(1, t+1):
    s = raw_input()
    a = s[0]
    for i in range(1, len(s)):
        if a[0] <= s[i]:
            a = s[i]+a
        else:
            a = a + s[i]
    print "Case #%d: %s" % (tc,a)