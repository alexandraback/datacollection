#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
from functools import lru_cache

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

@unroll('\n'.join)
def emit_matrix(B, start):
    yield start.zfill(B)
    for i in reversed(range(0, B-1)):
        yield ('1' * i).zfill(B)

@autosolve
@collects
def solve(B: int, M: int):
    if M > 2**(B-2):
        return "IMPOSSIBLE"

    if M == 2 ** (B-2):
        bin_result = bin(M-1)[2:] + '1'
    else:
        bin_result = bin(M)[2:] + '0'

    return '\n'.join(("POSSIBLE", emit_matrix(B, bin_result)))


