#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: work.py
# $Date: Sat Apr 12 23:04:59 2014 +0800
# $Author: jiakai <jia.kai66@gmail.com>

import numpy as np

SPACE = 0
MINE = 1
CLICK = 2

CHAR = {SPACE: '.', MINE: '*', CLICK: 'c'}

NO_SOLUTION = object()

def solve_case(nr_row, nr_col, nr_mine):
    if nr_row < nr_col:
        ans = solve_case(nr_col, nr_row, nr_mine)
        if ans is NO_SOLUTION:
            return ans
        return ans.T

    ans = np.empty((nr_row, nr_col), dtype='uint8')
    ans.fill(MINE)

    nr_space = nr_row * nr_col - nr_mine
    if nr_space <= 0:
        return NO_SOLUTION
    if nr_space == 1 or nr_col == 1:
        ans[:nr_space, 0] = SPACE
        return ans

    if nr_space <= 3:
        return NO_SOLUTION

    if nr_col == 2:
        if nr_space % 2:
            return NO_SOLUTION
        ans[:nr_space / 2, :] = SPACE
        return ans

    def block(c, force=False):
        x = nr_space / c
        y = nr_space % c
        if x >= 2 and y != 1:
            ans[:x, :c] = SPACE
            if y:
                ans[x, :y] = SPACE
            return ans
        assert not force

    if block(nr_col) is not None:
        return ans

    x = nr_space / nr_col
    if x >= 3:
        ans[:x-1, :] = SPACE
        ans[x-1, :nr_col-1] = SPACE
        ans[x, :2] = SPACE
        return ans

    if nr_space % 2 == 0:
        return block(min(nr_col - nr_col % 2, nr_space / 2), True)

    if nr_space <= 7:
        return NO_SOLUTION

    return block(min(nr_col - (nr_col + 1) % 2, nr_space / 2 - 1), True)


def read():
    return map(int, raw_input().split())

def main():
    nr_case, = read()

    for case in range(1, nr_case + 1):
        print 'Case #{}:'.format(case)
        R, C, M = read()
        ans = solve_case(R, C, M)
        if ans is NO_SOLUTION:
            print "Impossible"
            continue
        assert np.count_nonzero(ans == SPACE) == R * C - M, (R, C, M)
        ans[0][0] = CLICK
        for r in ans:
            print ''.join(map(CHAR.__getitem__, r))

main()
