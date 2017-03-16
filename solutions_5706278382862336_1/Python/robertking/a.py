__author__ = "google.com/+RobertKing"
from sys import stdin
from fractions import Fraction

data = (line for line in stdin.read().splitlines())

# data = '''5
# 1/2
# 3/4
# 1/4
# 2/23
# 123/31488'''.splitlines()

data = iter(data)
cases = int(next(data))

for case in range(1, cases + 1):
    P, Q = map(int, next(data).split('/'))
    frac = Fraction(P, Q)
    P = frac.numerator
    Q = frac.denominator
    g = 1
    while P * 2 ** g < Q:
        g += 1
    top = P * 2 ** g
    bottom = Q
    if (2**40 * top) % bottom != 0:
        ans = 'impossible'
    else:
        ans = g
    print "Case #%d: %s" % (case, ans)
