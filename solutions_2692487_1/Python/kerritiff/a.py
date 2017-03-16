def cal(a, m):
    ans = 0
    for i in m:
        if i < a:
            a += i
        elif a == 1:
            return 1000
        else:
            while i >= a:
                a += a-1
                ans += 1
            a += i
    return ans

def solve(a, n, m):
    ans = 1000
    m.sort()
    for i in xrange(n+1):
        x = cal(a, m[:n-i]) + i
        if x < ans:
            ans = x
    return ans


t = input()
for i in xrange(1, t+1):
    a, n = map(int, raw_input().split())
    m = map(int, raw_input().split())
    ans = solve(a, n, m)
    print 'Case #%d: %d' % (i, ans)
