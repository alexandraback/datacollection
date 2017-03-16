tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    x = map(int, raw_input().split())
    mx = max(x)
    ans = mx
    for k in xrange(1, mx):
        ank = sum([(xi-1)/k for xi in x]) + k
        if ans > ank:
            ans = ank
    print 'Case #%d: %d' % (t, ans)