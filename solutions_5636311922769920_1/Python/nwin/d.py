def solve():
    k, c, s = map(int, raw_input().split())
    if s * c < k:
        print "IMPOSSIBLE"
        return
    ans = [1] * s
    for i in xrange(k):
        ans[i % s] += i * (k ** (i / s))
    print " ".join(map(str, set(ans)))

T = int(raw_input())
for t in xrange(T):
    print "Case #%d:" % (t + 1),
    solve()
