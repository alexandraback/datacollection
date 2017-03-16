tt = int(raw_input())
for t in xrange(1, tt+1):
    (n, x) = raw_input().split()
    ans = 0
    cnt = 0
    for i in xrange(int(n)+1):
        if cnt < i:
            ans += i-cnt
            cnt = i
        cnt += int(x[i])
    print 'Case #%d: %d' % (t, ans)