
def solve(x, a, cnt):
    #print 'solve:', x, a, cnt
    if not a:
        return cnt
    if x > a[0]:
        return solve(x + a[0], a[1:], cnt)
    # x <= a[0]
    if x > 1:
        ans1 = solve(x * 2 - 1, a, cnt + 1)
        ans2 = cnt + len(a)
        return min(ans1, ans2)
    else:
        return cnt + len(a)

T = int(raw_input())
for t in xrange(T):
    A, n = map(int, raw_input().split())
    a = map(int, raw_input().split())
    a.sort()
    ans = solve(A, a, 0)
    print 'Case #%d: %d' % (t + 1, ans)
