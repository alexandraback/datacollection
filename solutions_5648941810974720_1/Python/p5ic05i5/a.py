from collections import defaultdict

T = int(raw_input())
for x in xrange(1, T+1):
    S = raw_input()
    F = defaultdict(lambda: 0)
    for c in S:
        F[c] += 1
    N = []

    def minLT(s):
        return min(F[c] for c in s)

    def takeout(n, s):
        global N
        m = minLT(s)
        if m > 0:
            N += [n] * m
            for c in s:
                F[c] -= m

    takeout(0, 'ZERO')
    takeout(2, 'TWO')
    takeout(4, 'FOUR')
    takeout(6, 'SIX')
    takeout(8, 'EIGHT')

    takeout(1, 'ONE')
    takeout(3, 'THREE')
    takeout(5, 'FIVE')
    takeout(7, 'SEVEN')
    takeout(9, 'NINE')

    print 'Case #{}: {}'.format(x, ''.join(map(str, sorted(N))))
