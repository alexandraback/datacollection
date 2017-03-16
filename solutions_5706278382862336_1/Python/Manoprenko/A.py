from math import floor
from fractions import Fraction

t = int(input())
for cycle in range(t):
    a, b = [int(i) for i in input().rstrip().split("/")]
    f = Fraction(a, b)
    f *= (2 ** 40)
    if floor(f) != f:
        print("Case #", cycle + 1, ": impossible", sep="")
    else:
        cnt = 40
        f = int(f)
        while f != 0:
            f //= 2
            cnt -= 1
        print("Case #", cycle + 1, ": ", cnt + 1, sep="")