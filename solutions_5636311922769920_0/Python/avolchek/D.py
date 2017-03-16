t = int(raw_input())

for tt in xrange(1, t + 1):
    k, c, s = map(int, raw_input().split())
    ans = ''
    if s * c < k:
        ans = 'IMPOSSIBLE'
    else:
        res = []
        p = 0
        for i in xrange(k / c + (k % c > 0)):
            n = 0
            for j in xrange(c):
                n = n * k + min(k - 1, p)
                p += 1
            res.append(str(n + 1))
        ans = ' '.join(res)
    print 'Case #{}: {}'.format(tt, ans)
