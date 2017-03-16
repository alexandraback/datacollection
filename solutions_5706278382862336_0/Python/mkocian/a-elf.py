# -*- coding: utf-8 -*-
import fractions

t = int(input())

for i in range(t):
    nom, denom = map(int, input().split('/'))
    f = fractions.Fraction(nom, denom)
    nom = f.numerator
    denom = f.denominator

    j = 1
    while j < denom:
        j *= 2

    if j > denom:
        print("Case #" + str(i+1) + ": impossible")
    else:
        k = 0

        while fractions.Fraction(1, 2**k) > f:
            k += 1

        print("Case #" + str(i+1) + ": " + str(k))
