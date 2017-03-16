#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def solve(rows, cols, mines):
    grid = []
    for i in range(rows):
        grid.append(["."] * cols)

    free = (rows * cols) - mines

    if free == 1:
        for r in range(rows):
            grid[r] = ["*"] * cols
        grid[rows - 1][cols - 1] = "c"
        return grid

    if rows == 1 and free > 0:
        for c in range(mines):
            grid[0][c] = "*"
        grid[rows - 1][cols - 1] = "c"
        return grid

    if cols == 1 and free > 0:
        for r in range(mines):
            grid[r][0] = "*"
        grid[rows - 1][cols - 1] = "c"
        return grid

    if free < 4:
        return None

    for i in range(2, rows+1):
        if free % i == 1:
            continue
        if (free // i) < 2:
            continue
        if free > cols * i:
            continue
        for r in range(rows - i):
            grid[r] = ["*"] * cols
        for r in range(rows - i, rows):
            for c in range(cols - (free // i)):
                grid[r][c] = "*"
            if rows - r <= free % i:
                grid[r][cols - (free // i) - 1] = "."
        grid[rows - 1][cols - 1] = "c"
        return grid

    for i in range(2, cols+1):
        if free % i == 1:
            continue
        if (free // i) < 2:
            continue
        if free > rows * i:
            continue
        for c in range(cols - i):
            for r in range(rows):
                grid[r][c] = "*"
        for c in range(cols - i, cols):
            for r in range(rows - (free // i)):
                grid[r][c] = "*"
            if cols - c <= free % i:
                grid[rows - (free // i) - 1][c] = "."
        grid[rows - 1][cols - 1] = "c"
        return grid

    for i in range(2, rows-1):
        if mines > i * (cols - 2):
            continue
        for r in range(i):
            for c in range(mines // i):
                grid[r][c] = "*"
            if r < mines % i:
                grid[r][mines // i] = "*"
        grid[rows - 1][cols - 1] = "c"
        return grid

    for i in range(2, cols-1):
        if mines > i * (rows - 2):
            continue
        for c in range(i):
            for r in range(mines // i):
                grid[r][c] = "*"
            if c < mines % i:
                grid[mines // i][c] = "*"
        grid[rows - 1][cols - 1] = "c"
        return grid

    return None

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

for casenr in range(1, ncases+1):
    arr = [ int(s) for s in getline().split() ]
    emit("Case #%d:\n", casenr)
    grid = solve(*arr)
    if not grid:
        emit("Impossible\n")
    else:
        count_m = 0
        for r in grid:
            for c in r:
                if c == "*":
                    count_m += 1
        if count_m != arr[2]:
            emit("Bad mine count!\n")
        for r in grid:
            emit("%s\n", "".join(r))
