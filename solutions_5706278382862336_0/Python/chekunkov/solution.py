# -*- coding: utf-8 -*-
# This library is available online and free to use:
# https://github.com/yanatan16/pycodejam
from codejam.parsers import iter_parser

# This library is available online and free to use:
# http://www.numpy.org/
import numpy as np

# https://code.google.com/p/gmpy/
from gmpy2 import mpfr, get_context, mpz, c_divmod, c_div, log2, gcd
from math import floor


def solve(*lines):
    P, Q = lines
    Q = mpz(Q)
    P = mpz(P)
    _gcd = gcd(P, Q)
    if gcd > 1:
        P = c_div(P, _gcd)
        Q = c_div(Q, _gcd)
    if not log2(Q).is_integer():
        return 'impossible'
    res = log2(P)
    res = mpz(floor(res))
    res, rem = c_divmod(Q, 2 ** res)
    if rem:
        return 'impossible'
    return int(log2(res))

@iter_parser
def parse(nxtline):
    P, Q = nxtline().split('/')
    return P, Q

if __name__ == "__main__":
    from codejam import CodeJam
    CodeJam(parse, solve).main()
