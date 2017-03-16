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

def triang(n):
    return (n * (n+1)) // 2

def prefix_accum(seq):
    s = 0
    for e in seq:
        yield s
        s += e

def all_orderings(B):
    for i in range(2 ** triang(B - 1)):
        b = bin(i)[2:]
        lengths = range(B-1, -1, -1)
        ordering = []
        for length, start in zip(lengths, prefix_accum(lengths)):
            ordering.append(tuple(int(i) for i in b[start:start+length]))
        yield tuple(ordering)

@lru_cache(maxsize=None)
def compute(ordering):
    if ordering == ((),):
        return 1

    head, rest = ordering[0], ordering[1:]
    total = 0

    for i, slide in enumerate(head):
        if slide:
            total += compute(rest[i:])

    return total

@autosolve
@collects
def solve(B: int, M: int):
    for ordering in all_orderings(B):
        if compute(ordering) == M:
            break
    else:
        return "IMPOSSIBLE"

    matrix = '\n'.join(''.join(map(str, r)).zfill(B) for r in ordering)

    return '\n'.join(("POSSIBLE", matrix))
