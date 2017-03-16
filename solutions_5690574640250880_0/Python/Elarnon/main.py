#!/usr/bin/env python3

import sys
import random

# Transpose a matrix
def transpose(x):
    return [list(y) for y in zip(*x)]

def check(r, c, m, x):
    if len(x) != r:
        return "Wrong number of rows (expected {}, got {}).".format(r, len(x))
    s = None
    i = 0
    nbomb = 0
    for row in x:
        if len(row) != c:
            return "Expected {} columns, got {} (at row {}).".format(c, len(row), i)
        j = 0
        for p in row:
            if p not in { ".", "*", "c" }:
                return "Invalid character `{}'.".format(p)
            if p == "c" and s is not None:
                return "Multiple clicks at ({}, {}) and ({}, {}).".format(s[0], s[1], i, j)
            if p == "c":
                s = (i, j)
            if p == "*":
                nbomb += 1
            j += 1
        i += 1
    if s is None:
        return "No click."
    if nbomb != m:
        return "Expected {} bombs, {} found.".format(m, nbomb)
    q = { s }
    while len(q) > 0:
        i, j = q.pop()
        if 0 <= i and i < r and 0 <= j and j < c:
            if x[i][j] in { ".", "c" }:
                add = { (i - 1, j - 1), (i - 1, j), (i - 1, j + 1), (i, j - 1), (i, j + 1), (i + 1, j - 1), (i + 1, j), (i + 1, j + 1) }
                n = 0
                for (a, b) in add:
                    if 0 <= a and a < r and 0 <= b and b < c:
                        if x[a][b] == "*":
                            n += 1
                            break
                x[i][j] = str(n)
                if n == 0:
                    q |= add
    i = 0
    for row in x:
        j = 0
        for p in row:
            if p == ".":
                return "Unreached free space at ({}, {}).".format(i, j)
            j += 1
        i += 1

def display(x):
    for r in x:
        print(''.join(r))

# r = 1
def one(c, m):
    return [["*"] * m + ["."] * (c - m - 1) + ["c"]]

# m = 0
def no_mines(r, c):
    res = []
    for i in range(0, r - 1):
        res.append(["."] * c)
    res.append(["."] * (c-1) + ["c"])
    return res

# mines everywhere but at one place
def one_click(r, c):
    res = []
    for i in range(0, r-1):
        res.append(["*"] * c)
    res.append(["*"] * (c - 1) + ["c"])
    return res

# r = 2, print "*****....." with nempties "."
#              "*****....c"
def two_rows(c, nempties):
    return [ ["*"] * (c - nempties) + ["."] * nempties ,
             ["*"] * (c - nempties) + ["."] * (nempties - 1) + ["c"] ]

# free = 4
def four(r, c):
    res = []
    for i in range(0, r - 2):
        res.append(["*"] * c)
    res.append(["*"] * (c - 2) + ["."] * 2)
    res.append(["*"] * (c - 2) + ["."] + ["c"])
    return res

# rem > 0 is free - k * r
# k in { 2, 3 }
def filling_rows(r, c, rem, k):
    res = []
    fix = None
    for i in range(0, r - 1):
        lasts = rem % r
        adjust = int((rem - lasts) / r)
        if lasts > 0:
            adjust += 1
            rem -= 1
        elif lasts == 0 and fix is None:
            if i != 1:
                fix = False
            else:
                adjust += 1
                fix = True
        res.append(["*"] * (c - k - adjust) + ["."] * (adjust + k))
    adjust = int(rem / r)
    if fix is True:
        adjust -= 1
    res.append(["*"] * (c - k - adjust) + ["."] * (adjust + (k-1)) + ["c"])
    return res

# free < 3 * r
def general_rows(r, c, free):
    res = []
    while free > 0:
        if free <= 3 * (r-1):
            res.append(["*"] * c)
            r -= 1
        elif (free % 3) == 0:
            if r == 1:
                res.append(["*"] * (c - 3) + ["."] + ["."] + ["c"])
                free -= 3
            else:
                res.append(["*"] * (c - 3) + ["."] * 3)
                free -= 3
            r -= 1
        elif (free % 3) == 1:
            res.append(["*"] * (c - 2) + ["."] * 2)
            res.append(["*"] * (c - 2) + ["."] * 2)
            r -= 2
            free -= 4
        else: # free % 3 == 2
            res.append(["*"] * (c - 2) + ["."] * 2)
            r -= 1
            free -= 2
    return res

# Recall that m < r * c
def solve(r, c, m):
    free = r * c - m
    # Trivial when there are no mines
    if m == 0:
        return no_mines(r, c)
    elif free == 1:
        # Trivial when there is only one empty case
        return one_click(r, c)
    # When r = 1 or c = 1, ***......c always work
    elif r == 1:
        return one(c, m)
    elif c == 1:
        return transpose(one(r, m))
    # When r = 2 or c = 2, possible IFF there is an
    # even number of free spaces... except when
    # there is only one (always possible) or exactly
    # two (the clicked case has at least 3 neighbors)
    elif r == 2:
        if free == 2 or (free % 2) == 1:
            return False
        else:
            return two_rows(c, int(free / 2))
    elif c == 2:
        if free == 2 or (free % 2) == 1:
            return False
        else:
            return transpose(two_rows(r, int(free / 2)))
    # r >= 3 and c >= 3
    else:
        # When we have at least 8 available spaces,
        # everything is possible in the following way:
        #  - For all the columns (or rows) but the last 3,
        #    fill them with mines (and then free spaces
        #    if needed)... except when a column should
        #    be all mines but one space (see filling_rows)
        #  - Then, if there is no mines, free spaces in
        #    the last 3 columns with a click anywhere there
        #    will propagate to all the free spaces.
        #  - Otherwise, there are three cases.
        #    + If free % 3 == 0, just stack "..." and
        #      then a 'c' on the bottom left. For the propagation
        #      to work, there must be at least 2 rows, so it
        #      starts at 6.
        #    + If free % 3 == 1, do the same but
        #      put a 2x2 square for the last 4 (this requires
        #      at least 2 rows filled with 3 '.' to work, so
        #      starting at 10)
        #    + If free % 3 == 2, do the same as in free % 3 == 0,
        #      and finish with a line with two '.' (again, needs
        #      at least 2 rows filled with 3 '.', so starting
        #      at 8)
        # Before that, we have the same restrictions as
        # in the two rows/two columns case.
        if free == 2 * r:
            return filling_rows(r, c, free - 2 * r, 2)
        elif free == 2 * c:
            return transpose(filling_rows(c, r, free - 2 * c, 2))
        elif free in [ 2, 3, 5, 7 ]:
            return False
        elif free == 4: # Remaining problem
            return four(r, c)
        elif free >= 3 * r: # Propagation
            return filling_rows(r, c, free - 3 * r, 3)
        elif free >= 3 * c:
            return transpose(filling_rows(c, r, free - 3 * c, 3))
        elif free % r != 1:
            return general_rows(r, c, free)
        elif free % c != 1:
            return transpose(general_rows(c, r, free))
        else:
            return general_rows(r, c, free)

def fuzzy(n):
    random.seed()
    for i in range(0, n):
        r = random.randint(1, 50)
        c = random.randint(1, 50)
        m = random.randint(0, r * c - 1)
        print("Checking r = {}, c = {}, m = {}...".format(r, c, m))
        res = solve(r, c, m)
        if res is not False:
            check(r, c, m, res)

if __name__ == '__main__':
    ncases = int(sys.stdin.readline())
    for i in range(1, ncases + 1):
        print("Case #{}:".format(i))
        [r, c, m] = [int(x) for x in sys.stdin.readline().split()]
        res = solve(r, c, m)
        if res is False:
            print("Impossible")
        else:
            display(res)
