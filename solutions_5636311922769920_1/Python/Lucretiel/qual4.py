#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
import math

# code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t)gen
#   solve(int_token: int, list_token: ('int_token', str), other_list: (None, float)):


def final_index(indexes, complexity, length):
    return sum(index * (length ** c)
               for index, c
               in zip(indexes, reversed(range(complexity))))


@autosolve
@collects
def solve(length: int, complexity: int, students: int):
    min_students = math.ceil(length / complexity)

    if students < min_students:
        return "IMPOSSIBLE"

    @unroll(tuple)
    def solution():
        indexes = range(length)
        for i in range(0, length, complexity):
            yield 1 + final_index(indexes[i:i+complexity], complexity, length)

    return solution()
