def calc(k, S, X):
    S.sort()
    lo, hi = 0.0, 1.0
    while lo < hi:
        c = (lo + hi) / 2.0

        y = 1.0 - c
        good = False
        for l in S:
            x = (k + X * c - l) / X
            y -= x
            if y < 0:
                good = True
                break

        if good and abs(hi - lo) < 0.000000001:
            return c
        if good:
            hi = c
        else:
            lo = c

    return 1.0

if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        S = [int(s) for s in raw_input().split()]
        N, S = S[0], S[1:]
        X = sum(S)

        Y = []
        for i in xrange(N):
            y = calc(S[i], S[:i] + S[i + 1:], X)
            Y += [y]

        print 'Case #%d: %s' % (caseno + 1, ' '.join('%.6f' % (y * 100.0) for y in Y))

