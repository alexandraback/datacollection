import fractions

t = int(raw_input())

for tt in xrange(t):
    p, q = map(int, raw_input().split('/'))
    d = fractions.gcd(p, q)
    p, q = p // d, q // d
    
    if (q & (q - 1)):
        print 'Case #{}: {}'.format(tt + 1, 'impossible')
    else:
        while p > 1:
            p //= 2
            q //= 2
        ans = 0
        x = 1
        while x != q:
            ans += 1
            x *= 2
        print 'Case #{}: {}'.format(tt + 1, ans)