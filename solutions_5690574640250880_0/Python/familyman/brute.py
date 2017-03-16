import sys
from itertools import *

_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())
D = lambda: float(_input.pop())

def solve_one():
    R, C, M = I(), I(), I()

    def neighbors(r, c):
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                if dr == dc == 0:
                    continue
                if r+dr < 0 or r+dr == R:
                   continue
                if c+dc < 0 or c+dc == C:
                    continue
                yield r+dr, c+dc

    def search(grid, ix, iy):
        seen = set()

        def dig(r, c):
            if grid[r][c] == '*':
                return -1E10

            seen.add((r, c,))
            if grid[r][c] == 0:
                for rr, cc in neighbors(r, c):
                    if grid[rr][cc] != '*' and not (rr, cc,) in seen:
                        dig(rr, cc)

        dig(ix, iy)
        return len(seen)

    coords = [(r, c) for r in range(R) for c in range(C)]
    for mine_pos in combinations(coords, M):
        grid = [[0 for c in range(C)] for r in range(R)]

        for r, c in mine_pos:
            grid[r][c] = '*'

            for rr, cc in neighbors(r, c):
                if grid[rr][cc] != '*':
                    grid[rr][cc] = 1

        for cr, cc in coords:
            if search(grid, cr, cc) == R*C-M:
                has_c = None
                no_zero = True
                for r in grid:
                    if 0 in r:
                        no_zero = False

                if no_zero:
                    k = 0
                    for r in grid:
                        for c in r:
                            if c == 1:
                                k += 1
                    assert k == 1

                for r in grid:
                    o = ''
                    for c in r:
                        if c == '*':
                            o += '*'
                        elif (c == 0 or no_zero) and not has_c:
                            o += 'c'
                            has_c = True
                        else:
                            o += '.'
                    print o
                return
    print 'Impossible'

for t in range(1, I()+1):
    print 'Case #%d:' % t
    solve_one()
