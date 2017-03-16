#!/usr/bin/python

from collections import deque

def testClick(R, C, grid):
    queue = deque()
    visited = set()
    for y in range(R):
        for x in range(C):
            if grid[y][x] == 'c':
                queue.append((x, y))
    assert len(queue) == 1
    while queue:
        x, y = queue.popleft()
        if (x, y) in visited or not (0 <= x < C) or not (0 <= y < R):
            continue

        visited.add((x, y))

        count = 0
        neighbors = []
        for yy in range(max(y - 1, 0), min(y + 2, R)):
            for xx in range(max(x - 1, 0), min(x + 2, C)):
                count += (grid[yy][xx] == '*')
                neighbors.append((xx, yy))

        if count == 0:
            queue.extend(neighbors)

    for y in range(R):
        for x in range(C):
            assert (grid[y][x] == '*') or ((x, y) in visited)

def wrap(R, C, M):
    return brute(R, C, M)
    r = solve(R, C, M) or zip(*solve(C, R, M))

    if not r:
        x = brute(R, C, M)
        if x != "Impossible":
            print
            print x
            assert False

        return "Impossible"
    else:
        x = brute(R, C, M)
        if x == "Impossible":
            print
            print s
            assert False

        s = '\n'.join(map(''.join, r))
        testClick(R, C, r)
        assert s.count('*') == M
        return s

def solve(R, C, M):
    grid = [['.' for i in range(C)] for j in range(R)]
    m = M
    try:
        if not m:
            return
        for i in range(R)[::-1]:
            for j in range(C)[::-1]:
                if grid[i][j] == '*':
                    continue

                if i == 1 and m > 1:
                    grid[0][j] = '*'
                    grid[1][j] = '*'
                    m -= 2
                elif j == 1 and m > 1:
                    grid[i][0] = '*'
                    grid[i][1] = '*'
                    m -= 2
                elif i == 0:
                    grid[0][j] = '*'
                    m -= 1
                elif j != 1 or m > 1 or i == 0:
                    grid[i][j] = '*'
                    m -= 1

                if not m:
                    return
    finally:
        if m:
            return []

        grid2 = [g[:] for g in grid]

        for y in range(R):
            for x in range(C):
                if grid[y][x] == '.':
                    count = 0
                    for yy in range(max(y - 1, 0), min(y + 2, R)):
                        for xx in range(max(x - 1, 0), min(x + 2, C)):
                            count += (grid[yy][xx] == '*')
                    grid2[y][x] = chr(ord('0') + count)

        numbered = 0
        connectedToZeros = True
        for y in range(R):
            for x in range(C):
                if grid[y][x] == '.':
                    numbered += 1
                    con = False
                    for yy in range(max(y - 1, 0), min(y + 2, R)):
                        for xx in range(max(x - 1, 0), min(x + 2, C)):
                            if grid2[yy][xx] == '0':
                                con = True
                    if not con:
                        connectedToZeros = False
        if numbered > 1 and not connectedToZeros:
            return []

        good = False
        for y in range(R):
            for x in range(C):
                if not good and grid2[y][x] == '0':
                    grid[y][x] = 'c'
                    good = True
        for y in range(R):
            for x in range(C):
                if not good and grid[y][x] == '.':
                    grid[y][x] = 'c'
                    good = True

        if not good:
            return []

        return grid

def brute(R, C, M):
    from itertools import combinations
    for combo in combinations(range(R * C), M):
        grid = [['.' for x in range(C)] for y in range(R)]
        for idx in combo:
            grid[idx / C][idx % C] = '*'

        grid2 = [g[:] for g in grid]

        for y in range(R):
            for x in range(C):
                if grid[y][x] == '.':
                    count = 0
                    for yy in range(max(y - 1, 0), min(y + 2, R)):
                        for xx in range(max(x - 1, 0), min(x + 2, C)):
                            count += (grid[yy][xx] == '*')
                    grid2[y][x] = chr(ord('0') + count)

        numbered = 0
        connectedToZeros = True
        for y in range(R):
            for x in range(C):
                if grid[y][x] == '.':
                    numbered += 1
                    con = False
                    for yy in range(max(y - 1, 0), min(y + 2, R)):
                        for xx in range(max(x - 1, 0), min(x + 2, C)):
                            if grid2[yy][xx] == '0':
                                con = True
                    if not con:
                        connectedToZeros = False
        if numbered > 1 and not connectedToZeros:
            continue

        good = False
        for y in range(R):
            for x in range(C):
                if not good and grid2[y][x] == '0':
                    grid[y][x] = 'c'
                    good = True
        for y in range(R):
            for x in range(C):
                if not good and grid[y][x] == '.':
                    grid[y][x] = 'c'
                    good = True

        if not good:
            continue

        try:
            testClick(R, C, grid)
            return '\n'.join(map(''.join, grid))
        except AssertionError:
            pass
    return "Impossible"

T = int(raw_input())
for i in range(T):
    print "Case #%i:\n%s" % (i+1, wrap(*(int(s) for s in raw_input().split(' '))))
