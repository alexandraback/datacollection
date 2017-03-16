#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
from collections import Counter
from fractions import gcd
from itertools import islice

def lcm(x, y):
    return x * y // gcd(x, y)

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

def loop_range(max, step):
    x = 0
    for _ in range(max):
        yield x
        x = (x + step) % max

def outfits(J, P, S):
    step = lcm(lcm(J, P), S) - 1
    for j in loop_range(J, step):
        for p in loop_range(P, step):
            for s in loop_range(S, step):
                yield j, p, s


def emit_fashion(J, P, S, K):
    js_counts = Counter()
    ps_counts = Counter()
    jp_counts = Counter()

    for j, p, s in islice(outfits(J, P, S), J*P*S):
        debug((j, p, s))
        if jp_counts[j, p] >= K:
            continue
        if js_counts[j, s] >= K:
            continue
        if ps_counts[p, s] >= K:
            continue

        yield j, p, s
        js_counts[j, s] += 1
        ps_counts[p, s] += 1
        jp_counts[j, p] += 1
        debug('js: {}, ps: {}, jp: {}'.format(js_counts, ps_counts, jp_counts))

def emit_solution(fashion):
    fashion = tuple(fashion)
    yield str(len(fashion))
    for outfit in fashion:
        yield ' '.join(str(o + 1) for o in outfit)

@autosolve
@collects
def solve(J: int, P: int, S: int, K: int):
    fashion = emit_fashion(J, P, S, K)
    return '\n'.join(emit_solution(fashion))
