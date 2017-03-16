#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *

#code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t) gen, @trace func|gen
#   solve(int_token: int, list_token: ('int_token', str)):

def lookahead(it):
    it = iter(it)

    a = next(it)

    for b in it:
        yield a, b
        a = b

    yield a, None


def matches(d1, d2):
    return all(d1 == d2 or d1 == '?' or d2 == '?' for d1, d2 in zip(d1, d2))

@autosolve
@collects
def solve(C: str, J: str):
    c_result = []
    j_result = []
    prev_type = None
    larger = ''
    subtraction_slot = None

    for i, (c, j) in enumerate(zip(C, J)):
        if larger == '':
            if c == j:
                if c == '?':
                    c_result.append('0')
                    j_result.append('0')
                else:
                    c_result.append(c)
                    j_result.append(j)
            elif c == '?':
                prev_type = 'C'
                c_result.append(j)
                j_result.append(j)
            elif j == '?':
                prev_type = 'J'
                c_result.append(c)
                j_result.append(c)
            elif int(c) > int(j):
                if int(c) - int(j) == 5 and prev_type == 'C':
                    subtraction_slot = ('C', i - 1)
                    larger = 'J'
                else:
                    larger = 'C'
                c_result.append(c)
                j_result.append(j)
            elif int(j) > int(c):
                if int(j) - int(c) == 5 and prev_type == 'J':
                    subtraction_slot = ('J', i - 1)
                    larger = 'C'
                else:
                    larger = 'J'
                c_result.append(c)
                j_result.append(j)
            else:
                raise RuntimeError()
        elif larger == 'C':
            if c == j:
                if c == '?':
                    c_result.append('0')
                    j_result.append('9')
                else:
                    c_result.append(c)
                    j_result.append(j)
            elif c == '?':
                c_result.append('0')
                j_result.append(j)
            elif j == '?':
                c_result.append(c)
                j_result.append('9')
            else:
                c_result.append(c)
                j_result.append(j)
        elif larger == 'J':
            if c == j:
                if c == '?':
                    c_result.append('9')
                    j_result.append('0')
                else:
                    c_result.append(c)
                    j_result.append(j)
            elif c == '?':
                c_result.append('9')
                j_result.append(j)
            elif j == '?':
                c_result.append(c)
                j_result.append('0')
            else:
                c_result.append(c)
                j_result.append(j)

    c_result = int(''.join(map(str, c_result)))
    j_result = int(''.join(map(str, j_result)))

    if subtraction_slot is not None:
        subtract_target, index = subtraction_slot
        subtract_value = 10**(len(C) - index)
        if subtract_target == 'C' and subtract_value <= c_result:
            c_result -= subtract_value
        elif subtract_target == 'J' and subtract_value <= j_result:
            j_result -= subtract_value

    return [str(r).zfill(len(C)) for r in (c_result, j_result)]

