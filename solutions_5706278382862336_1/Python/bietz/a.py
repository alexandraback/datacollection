
T = int(raw_input())

def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(b, a % b)

for t in range(1, T+1):
    P, Q = map(long, raw_input().split('/'))
    g = gcd(P,Q)
    p, q = P/g, Q/g
    pp = q
    imp = False
    while (pp >> 1) != 0:
        imp = imp or pp % 2 == 1
        pp >>= 1
    if p > q or imp:
        print 'Case #{}: impossible'.format(t)
        continue

    res = 1
    while p < (q >> 1):
        res += 1
        q >>= 1

    print 'Case #{}: {}'.format(t, res)
