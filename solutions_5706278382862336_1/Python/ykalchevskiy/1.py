from fractions import Fraction, gcd


ri = lambda: int(raw_input())
rii = lambda: list(map(int, raw_input().split()))


h = Fraction(1, 2)


def solve():
    p, q = map(int, raw_input().split('/'))
    f = Fraction(p, q)
    n = f.numerator
    d = f.denominator
    if d & (d - 1):
        print 'impossible'
    else:
        g = 1
        while f < h:
            f *= 2
            g += 1
        print g


tt = ri()

for t in range(tt):
    print 'CASE #' + str(t + 1) + ':',
    solve()
