def solve(s):
    n = len(s)
    ans = s[0]
    for i in range(1, n):
        if ord(ans[0]) <= ord(s[i]):
            ans = s[i] + ans
        else:
            ans = ans + s[i]
    return ans

T = int(raw_input())
for t in xrange(T):
    s = raw_input()
    ans = solve(s)
    print 'Case #' + str(t+1) + ': ' + ans
