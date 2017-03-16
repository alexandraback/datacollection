tt = int(raw_input())
for t in xrange(1, tt+1):
    k, c, s = map(int, raw_input().strip().split())
    if s * c < k:
        ans = 'IMPOSSIBLE'
    else:
        d = []
        s = min((k+c-1)/c, s)
        for i in xrange(s):
            y = [min(j+i*c, k-1) for j in xrange(c)]
            num = 0
            for z in y:
                num *= k
                num += z
            d.append(num+1)
        ans = ' '.join(map(str, d))
    print 'Case #%d: %s' % (t, ans)