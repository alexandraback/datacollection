T = int(raw_input())

for t in range(T):
    ans = 0
    s = raw_input()
    for i in range(1, len(s)):
        if s[i] != s[i-1]:
            ans += 1

    if s[-1] == '-':
        ans += 1

    print 'Case #%d: %d' % (t + 1, ans)
