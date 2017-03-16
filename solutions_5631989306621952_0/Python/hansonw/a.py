T = int(raw_input())

for t in range(T):
    s = raw_input()
    ans = ''
    for c in s:
        a = ans + c
        b = c + ans
        ans = max(a, b)
    print 'Case #%d: %s' % (t+1, ans)
