from fractions import Fraction
import sys


def log(*a, **kw):
    print(*a,file=sys.stderr, **kw)


def fraction(p,q):
    return Fraction(p) / Fraction(q)


def solve(f):
    if not possible(f.denominator):
        return "impossible"
    i = 1
    a = 2
    while f < fraction(1,a):
        a *= 2
        i += 1
    return i


def possible(q):
    """Check q is a factor of 2"""
    s = '{:b}'.format(q)
    if s[0] != '1':
        return False
    if int(s[1:], 2) != 0:
        return False
    return True


def main(t):
    f = Fraction(input())
    i = solve(f)
    print("Case #%s: %s" % (t, i))


T = int(input())
for t in range(T):
    main(t+1)
