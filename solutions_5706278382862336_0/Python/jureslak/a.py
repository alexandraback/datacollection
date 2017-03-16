from fractions import Fraction as f
from math import log


def valid(a,n=40):
    return not (a < 0 or (a.denominator & (a.denominator - 1)) or (log(a.denominator) > n))

t = int(input())
for asdf in range(t):
    a = f(input())
    if (a == 0 or a.denominator & (a.denominator - 1)) or (log(a.denominator) > 40):
        print ("Case #{}: {}".format(asdf+1, "impossible"))
        continue

    if a == 1:
        print ("Case #{}: {}".format(asdf+1, 0))
        continue

    # denominator is a power of 2
    n = 1
    while n <= 40:
        p = 2*a - 1
        if valid(p,40-n):
            break
        a = 2*a
        n += 1

    if n == 41:
        print ("Case #{}: {}".format(asdf+1, "impossible"))
    else:
        print ("Case #{}: {}".format(asdf+1, n))
