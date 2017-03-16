def solve():
    n = int(raw_input())
    a = []
    for i in xrange(n):
        d, h, m = map(int, raw_input().split())
        for j in xrange(h):
            a.append((360 - d, m + j))
    N = len(a)
    if N <= 1:
        return 0
    b = []
    for i, x in enumerate(a):
        b.append((x[0] * x[1], i))
    b.sort(reverse=True)
    ans = 0
    for i in xrange(N):
        k = 0
        for j in xrange(i + 1, N):
            t = (b[i][0] - b[j][0]) / (360 * a[b[j][1]][1])
            k += max(t, 0)
        ans += min(k, 1)
    return ans

T = int(raw_input())
for t in xrange(T):
    print "Case #%d: %d" % (t + 1, solve())
