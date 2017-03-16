import sys
from fractions import Fraction

import math

def main(input):
    T = int(input.readline())

    for i in range(T):
        print "Case #%s:"% (i+1),

        a, b = map(int, input.readline().split('/'))

        f = Fraction(a, b)
        a = f.numerator
        b = f.denominator

        r = a / float(b)
        k = math.log(b, 2)

        if 2 ** int(k) != b:
            print 'impossible'
            continue

        for j in range(1, 40):
            if Fraction(1, 2**j) <= f:
                print j
                break





main(sys.stdin)
