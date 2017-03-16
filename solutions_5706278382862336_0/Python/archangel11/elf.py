from fractions import Fraction

impossible = "impossible"

def solve(f):
    p,q = map(int, f.readline().split("/"))

    f = Fraction(p,q)
    n = f.numerator
    d = f.denominator

    while n > 1:
        f -= Fraction(1,d)
        n = f.numerator
        d2 = f.denominator
        if d == d2:
            return impossible
        d = d2


    i = 0
    while d > 1:
        if d%2 != 0:
            return impossible
        d /= 2
        i += 1


    if i > 40:
        return impossible

    return i
