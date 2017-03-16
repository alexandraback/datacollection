#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
from functools import lru_cache

# code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t)gen
#   solve(int_token: int, list_token: ('int_token', str), other_list: (None, float)):

G = '+'
B = '-'

@lru_cache()
@unroll(''.join)
def flip(stack):
    for i in reversed(stack):
        yield B if i == G else G


@lru_cache()
@unroll(''.join)
def flip_head(stack):
    stack = iter(stack)

    while next(stack) == G:
        yield B

    yield B
    yield from stack

def num_flips(stack):
    stack = stack.rstrip(G)

    if not stack:
        return 0

    flips = 0

    if stack[0] == G:
        stack = flip_head(stack)
        flips += 1

    stack = flip(stack)
    flips += 1

    return flips + num_flips(stack)


@autosolve
@collects
def solve(stack: str):
    return num_flips(stack)
