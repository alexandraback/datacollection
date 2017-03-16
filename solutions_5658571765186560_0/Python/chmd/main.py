#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import sys


def read_tests(instance_file):
    with open(instance_file) as f:
        n = int(f.next().strip('\n'))
        for _ in range(n):
            x, r, c = [int(i) for i in f.next().strip('\n').split()]
            yield (x, r, c)

ominos = {
        1: [
            [[1]]
           ],
        2: [
            [[1, 1],
             [0, 0]],
           ],
        3: [
            [[1, 1, 1],
             [0, 0, 0],
             [0, 0, 0]],
            [[1, 1, 0],
             [1, 0, 0],
             [0, 0, 0]]
           ],
        4: [
            [[1, 1, 0, 0],
             [1, 1, 0, 0],
             [0, 0, 0, 0],
             [0, 0, 0, 0]],
            [[1, 1, 0, 0],
             [1, 0, 0, 0],
             [1, 0, 0, 0],
             [0, 0, 0, 0]],
            [[1, 0, 0, 0],
             [1, 1, 0, 0],
             [1, 0, 0, 0],
             [0, 0, 0, 0]],
            [[1, 0, 0, 0],
             [1, 1, 0, 0],
             [0, 1, 0, 0],
             [0, 0, 0, 0]],
            [[1, 0, 0, 0],
             [1, 0, 0, 0],
             [1, 0, 0, 0],
             [1, 0, 0, 0]]
           ]
        }

def rotate(m):
    n = len(m)
    res = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            res[i][j] = m[n-1-j][i]
    return res

def flip(m):
    n = len(m)
    res = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            res[i][j] = m[i][n-1-j]
    return res

def all_versions(m):
    yield m
    for _ in range(3):
        m = rotate(m)
        yield m
    m = flip(m)
    yield m
    for _ in range(3):
        m = rotate(m)
        yield m

def show(m):
    for row in m:
        print row

def valid(grid):
    for row in grid:
        for e in row:
            if e not in (0, 1):
                return False
    return True

def positions(grid, n):
    r = len(grid)
    c = len(grid[0])
    for i in range(-n, r):
        for j in range(-n, c):
            yield (i, j)

def all_ominos(n):
    for i in ominos[n]:
        for v in all_versions(i):
            yield v

def solved(grid):
    for row in grid:
        for e in row:
            if e != 1:
                return False
    return True

def try_put(grid, omino, position):
    r = len(grid)
    c = len(grid[0])
    g = [row[:] for row in grid]
    x, y = position
    n = len(omino)
    for i in range(n):
        for j in range(n):
            if omino[i][j] == 1:
                if 0 <= x+i < r and 0 <= y+j < c and g[x+i][y+j] == 0:
                    g[x+i][y+j] = 1
                else:
                    return None
    return g


def solvable(grid, n, initial=None):
    #print("considering grid:")
    #show(grid)

    if solved(grid):
        #print ("it is solved!")
        return True

    if initial:
        to_try = all_versions(initial)
    else:
        to_try = all_ominos(n)
    for o in to_try:
        #print("trying to position omino:")
        #show(o)
        for p in positions(grid, n):
            #print("at position %s" % str(p))
            newgrid = try_put(grid, o, p)
            if newgrid:
                #print("it worked!")
                if solvable(newgrid, n):
                    return True
            #print("it failed...")
    return False


def solve_instance(instance):
    x, r, c = instance

    # Richard can create a hole
    if x >= 7:
        return "RICHARD"

    # The grid has not the correct number of slots
    if (r * c) % x != 0:
        return "RICHARD"

    if x > r and x > c:
        return "RICHARD"

    for o in ominos[x]:
        grid = [[0 for _ in range(c)] for _ in range(r)]
        if not solvable(grid, x, initial=o):
            return "RICHARD"

    return "GABRIEL"


if __name__ == "__main__":
    if len(sys.argv[1:]) != 1:
        exit("Expected 1 argument, got %i" % len(sys.argv[1:]))

    instance_file = sys.argv[1]

    for i, instance in enumerate(
            read_tests(instance_file), start=1
            ):
        print("Case #%i: %s" % (i, solve_instance(instance)))
