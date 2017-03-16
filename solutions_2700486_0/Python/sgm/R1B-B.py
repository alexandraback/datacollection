
memo = {}

def C(n, r):
    if n == 1 or r == 0 or r == n:
        return 1
    if (n, r) in memo:
        return memo[(n, r)]
    c = C(n - 1, r - 1) + C(n - 1, r)
    memo[(n, r)] = c
    return c

def calc(N, X, Y):
    slide = X + Y
    level = slide / 2
    inner = level * (slide - 1)
    if inner + Y >= N:
        return 0.0
    elif inner + slide + Y < N:
        return 1.0
    n = N - inner
    if X == 0:
        if n < 2 * slide + 1:
            return 0.0
        else:
            return 1.0
    f = float(sum([C(n, r) for r in xrange(Y + 1, n + 1)]))
    for i in xrange(n):
        f /= 2
    return f

T = int(raw_input())
for t in xrange(T):
    s = raw_input().split()
    N = int(s[0])
    X = abs(int(s[1]))
    Y = int(s[2])
    print "Case #%d: %f" % (t + 1, calc(N, X, Y))
