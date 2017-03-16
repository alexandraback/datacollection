#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *

# code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t)gen
#   solve(int_token: int, list_token: ('int_token', str), other_list: (None, float)):


@autosolve
@collects
def solve(K: int, C: int, S: int):
    return list(i+1 for i in range(S))
