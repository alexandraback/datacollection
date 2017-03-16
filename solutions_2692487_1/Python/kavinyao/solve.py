# -*- coding:utf-8 -*-
import os
import sys
import math
import itertools


def let_armin_eat(A, barrier):
    """A > 1"""
    ops = int(math.floor(math.log((barrier-1.0)/(A-1.0), 2) + 1))
    A = (A-1) * 2**ops + 1
    return A, ops


def solve(A, motes):
    """Return minimal operations to take
    A - the current motes Armin has
    motes - descendingly ordered list of motes to eat
    """
    # eat as many as Armin can
    while motes and motes[-1] < A:
        # just eat it
        A += motes.pop()
        # print motes

    # print
    if not motes:
        return 0

    # print A
    if A == 1:
        # special case, just give up
        return len(motes)

    # two choices:
    # 1. add motes to eat and continue, or
    # 2. just give up
    A, min_add_ops = let_armin_eat(A, motes[-1])
    give_up_ops = len(motes)
    # print A, min_add_ops, give_up_ops

    if give_up_ops <= min_add_ops:
        # not worth trying
        return give_up_ops
    else:
        # see how far we can go...
        # safe to pass motes as it will be used only once
        add_ops = min_add_ops + solve(A, motes)
        return min(add_ops, give_up_ops)


if __name__ == '__main__':
    in_file = sys.argv[1]
    out_file = os.path.splitext(in_file)[0] + '.out'
    #print out_file
    output = open(out_file, 'w')

    with open(in_file) as test:
        rounds = int(test.next())
        print rounds, 'rounds'

        for i in xrange(rounds):
            print 'round', i+1
            A, N = map(int, test.next().split())

            motes = map(int, test.next().split())
            motes.sort(reverse=True)

            res = solve(A, motes)
            #print res
            output.write("Case #%d: %s\n" % (i+1, res))
            #print

    output.close()
