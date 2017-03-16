def nck(n, k):
    if n - k < k: k = n - k
    u, d = 1, 1
    for i in xrange(k):
        u *= (n - k + 1 + i)
        d *= (1 + i)
    return u/d
def S(k, x, _c = {}):
    if (k, x) in _c:
        return _c[k, x]
    if x > 0:
        v = S(k, x - 1) + nck(k, x)
    elif x == 0:
        v = 1
    else:
        v = 0
    _c[k, x] = v
    return v

def init(n):
    for i in xrange(n):
        S(n, i)

init(20)

def solve(n, x, y):
    x = abs(x)
    L = 1
    while L * (2 * L - 1) <= n:
        L += 1
    m = (L - 1) * (2 * L - 3)
    k = n - m
    # print 'n, L, m, k', n, L, m, k
    if (x + y) % 2: 
        return 0.
    if x + y <= 2 * (L - 2):
        return 1.
    if k > 0:
        if x + y != 2 * (L - 1):
            return 0
        if k >= y:
            h = y + 1
            # print 'h, x, y', h, x, y
            # for i in xrange(k + 1): print S(k, i),
            # print
            total = S(k, min(2*(L-1), k)) - S(k, max(0,  k-2*(L-1))-1)
            # print 'total:', total
            # print min(k, 2*(L-1)), max(h, k-2*(L-1))-1
            p = 10 ** 8 * (S(k, min(k, 2*(L-1))) - S(k, max(h, k-2*(L-1))-1)) / total * 1e-8
        else:
            p = 0.
    elif x + y == 2 * (L - 1):
        return 1.
    else:
        p = 0.
    return p

T = int(raw_input())
for t in xrange(T):
    n, x, y = map(int, raw_input().split())
    p = solve(n, x, y)
    assert 0 <= p <= 1
    print 'Case #%d: %.7f' % (t + 1, p)
