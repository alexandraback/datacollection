#!/usr/bin/env python3

# This code jam solution is powered by Nathan West's LibCodeJam; see
# https://github.com/Lucretiel/LibCodeJam for source code and (ostensibly) some
# documentation.

from code_jam import *
from itertools import count
from collections import defaultdict
import sys

sys.setrecursionlimit(3000)

# import code_jam; code_jam.INSERT_NEWLINE = True

# quick reference:
#   @autosolve, @collects, @cases(n)
#   tokens.token(t), tokens.many(n, t)
#   debug(expr), @unroll(t)gen
#   solve(int_token: int, list_token: ('int_token', str)):


def reduce(bffs):
    while True:
        targets = set(bffs.values())
        new_bffs = {student: bffs[student] for student in bffs if student in targets}
        debug("REDUCING\n\tFROM: {}\n\tTARGETS: {}\n\tTO: {}".format(bffs, targets, new_bffs))
        if len(new_bffs) == len(bffs):
            return new_bffs
        else:
            bffs = new_bffs


def chain_length(start, ignore, targets, bffs):
    to_check = [start]

    for length in count():
        to_check = [reverse_bff for student in to_check for reverse_bff in targets[student] if reverse_bff != ignore]
        if not to_check:
            return length


@autosolve
@collects
def solve(N: int, bffs: ('N', int)):
    bffs = {student: bff for student, bff in enumerate(bffs, 1)}
    reduced_bffs = reduce(bffs)

    debug("REDUCED TO: {}".format(reduced_bffs))

    best_cycle = 0

    #METHOD 1: Longest cycle
    def get_kill(student):
        target = reduced_bffs[student]
        del reduced_bffs[student]
        return target

    def cycle(start):
        current = get_kill(start)
        for i in count(1):
            if current == start:
                return i
            current = get_kill(current)

    while reduced_bffs:
        student = next(iter(reduced_bffs))
        best_cycle = max(best_cycle, cycle(student))

    if best_cycle > 1000:
        debug("FOUND TOO-LARGE CYCLE: {}\n{}\n{}".format(best_cycle, reduced_bffs, bffs))
        assert False

    #METHOD 2: TREES

    # First, find all the pairs
    pairs = {tuple(sorted((student, bff))) for student, bff in bffs.items() if bffs[bffs[student]] == student}

    # Next, reverse the bff tree
    targets = defaultdict(list)
    for student, bff in bffs.items():
        targets[bff].append(student)

    best_chain = 0
    # Next, for each student in each pair, find the longest chain.
    # every pair can sit with their chain, so add them all up
    for pair in pairs:
        best_chain += 2
        best_chain += chain_length(pair[0], pair[1], targets, bffs)
        best_chain += chain_length(pair[1], pair[0], targets, bffs)

    if best_chain > 1000:
        debug("FOUND TOO-LARGE CHAIN: {}\n{}\n{}".format(best_chain, pairs, bffs))

    return max(best_chain, best_cycle)
