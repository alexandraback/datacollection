# coding: utf-8

import sys
import math
import decimal

decimal.getcontext().prec = 100

def solve(r, t):
    a = decimal.Decimal(2)
    b = decimal.Decimal(2 * r - 1)
    c = decimal.Decimal(-t)
    y = (-b + (b * b - 4 * a * c).sqrt()) / (2 * a)
    return int(y)

if __name__ == '__main__':

    with open(sys.argv[1]) as f:
        lines = list(reversed(f.read().split('\n')))
        T = int(lines.pop())
        for case in range(T):
            r, t = map(int, lines.pop().split())
            result = solve(r, t)
            print 'Case #{}: {}'.format(case + 1, result)

