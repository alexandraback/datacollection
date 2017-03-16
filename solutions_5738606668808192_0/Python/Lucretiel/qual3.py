#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
import code_jam
from itertools import product, islice

code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t)gen
#   solve(int_token: int, list_token: ('int_token', str)):


def gen_coins(N, J):
    middle_length = (N - 4) // 2
    middle_parts = (''.join(part) for part in
                    islice(product(('00', '11'), repeat=middle_length), J))

    for middle in middle_parts:
        value = '11{}11'.format(middle)
        yield ' '.join((value, *map(str, range(3, 12))))


@autosolve
@collects
def solve(N: int, J: int):
    return '\n'.join(gen_coins(N, J))
