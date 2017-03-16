#!/usr/local/bin/python3.4 -tt

import fractions
import sys

if __name__ == '__main__':
    def _(f):
        for l in f:
            for i in l.split():
                yield i

    g = _(sys.stdin)

    T = int(next(g))

    for t in range(1, T + 1):
        p, q = tuple(int(i) for i in next(g).split('/'))

        f = fractions.Fraction(p, q)

        print('t=%d f=%d/%d' % (t, f.numerator, f.denominator), file=sys.stderr)

        denom = bin(f.denominator)[2:]

        if denom.count('1') == 1:
            c = 0
            while f < 1:
                f *= 2
                c += 1
            print('Case #%d: %d' % (t, c))
        else:
            print('Case #%d: impossible' % t)
