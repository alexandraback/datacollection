def solve(ix):
    A, B, K = map(int, raw_input().strip().split())
    ans = 0
    for i in xrange(A):
        for j in xrange(B):
            if i & j < K:
                ans += 1
    print 'Case #%d: %d' % (ix, ans)   

T = int(raw_input())
for ix in range(T):
    solve(ix+1)
