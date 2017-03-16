#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
from fileparser import FileParser


def count(b, m, solution):
    changed = True
    num = [0] * b
    num[b - 1] = 1
    while changed:
        changed = False
        for src in range(b-1):
            tot = 0
            for dst in range(b):
                if solution[src][dst]:
                    tot += num[dst]
            if tot > num[src]:
                changed = True
                num[src] = tot
            elif tot < num[src]:
                assert False
    #print b, m, num
    return num[0]

def check(b, m, solution):
    assert solution is not None

    assert len(solution) == b
    for i in range(b):
        assert len(solution[i]) == b

    for i in range(b):
        for j in range(b):
            assert solution[i][j] in (True, False)

    for i in range(b):
        assert solution[i][i] == False
    for i in range(b):
        assert solution[b-1][i] == False

    # TODO: must be a dag
    assert count(b, m, solution) == m, (count(b, m, solution), m)


def solve(b, m):
    """ solution[i][j] === going from i to j """
    if m > 2 ** (b - 2):
        return None

    solution = [[False] * b for _ in range(b)]

    for src in range(b):
        for dst in range(b):
            if src > 0 and dst > src:
                solution[src][dst] = True

    rem = m

    for index in range(1, b):
        x = b - index
        if x >= 2:
            num = 2 ** (x - 2   )
        elif x == 1:
            num = 1
        else:
            assert False, (index, b, x)
        #print "rem {} num {}".format(rem, num)
        if rem >= num:
            rem -= num
            solution[0][index] = True

    assert rem == 0, rem

    check(b, m, solution)
    return solution


def main():
    inputfile = FileParser()
    T = inputfile.read_int()
    for test in range(1, T + 1):
        B, M = inputfile.read_integers()

        solution = solve(B, M)

        if solution is None:
            print "Case #{}: IMPOSSIBLE".format(test)
        else:
            print "Case #{}: POSSIBLE".format(test)
            for row in solution:
                print "".join(["1" if x else "0" for x in row])
                pass


if __name__ == '__main__':
    main()
