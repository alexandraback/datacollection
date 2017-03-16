import fractions

def solve(hikers):
    if len(hikers) < 2:
        return 0

    h1 = hikers[0]
    h2 = hikers[1]


    # will they meet?
    a = fractions.Fraction(360, h1[1])
    c = h1[0]
    b = fractions.Fraction(360, h2[1])
    d = h2[0]

    if a == b:
        return 0

    if c != d:
        x1 = fractions.Fraction(360 - c, a)
        x2 = fractions.Fraction(360 - d, b)

        x = max(x1, x2)
        R = (d - c) / (a - b)

        if R > x:
            return 0

    if c == d:
        if a < b:
            a, b = b, a
            c, d = d, c

        c = c - 360

        x = fractions.Fraction(360 - d, b)
        R = (d - c) / (a - b)

        if R > x:
            return 0

    return 1

T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())

    hikers = []
    for j in xrange(N):
        D, H, M = [int(x) for x in raw_input().split()]

        for k in xrange(H):
            hikers.append((D, M + k,))

    print 'Case #%d: %d' % (i + 1, solve(hikers))
