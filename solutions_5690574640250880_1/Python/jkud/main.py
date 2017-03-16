#!/usr/bin/env python

def place(grid, r, c, char):
    grid[r] = grid[r][:c] + char + grid[r][c+1:]


def reveal(grid, r, c):
    R = len(grid)
    C = len(grid[0])
    if grid[r][c] != '.': return
    cnt = sum(grid[nr][nc] == '*' for nr in range(max(0, r-1), min(R, r+2)) for nc in range(max(0, c-1), min(C, c+2)))
    place(grid, r, c, str(cnt))
    if grid[r][c] == '0':
        for nr in range(max(0, r-1), min(R, r+2)):
            for nc in range(max(0, c-1), min(C, c+2)):
                reveal(grid, nr, nc)


def possible_in_1_click(grid, r, c):
    reveal(grid, r, c)
    return not any('.' in row for row in grid)


def solve(R, C, M):
    grid = ['*' * C for _ in range(R)]
    D = R * C - M
    if D == 1:
        place(grid, 0, 0, '.')
    elif R == 1:
        for c in range(D):
            place(grid, 0, c, '.')
    elif C == 1:
        for r in range(D):
            place(grid, r, 0, '.')
    elif D in [2, 3, 5, 7]:
        return 'Impossible'
    elif D >= 2 * C + 2:
        r = 0
        while D > C:
            grid[r] = '.' * C
            D -= C
            r += 1
        if D == 1:
            if C == 2:
                return 'Impossible'
            place(grid, r-1, C-1, '*')
            place(grid, r, 0, '.')
            place(grid, r, 1, '.')
        else:
            for c in range(D):
                place(grid, r, c, '.')
    else:
        tc = D / 2
        if D % 2 == 1:
            tc -= 1
        if tc < 2:
            return 'Impossible'
        for c in range(tc):
            place(grid, 0, c, '.')
            place(grid, 1, c, '.')
        D -= 2 * tc
        if D > 0 and R <= 2:
            return 'Impossible'
        for c in range(D):
            place(grid, 2, c, '.')
    grid_str = '\n'.join(grid)
    grid_str = 'c' + grid_str[1:]
    # assert possible_in_1_click(grid, 0, 0)
    return grid_str


T = int(raw_input().strip())
for t in range(T):
    R, C, M = [int(i) for i in raw_input().strip().split()]
    print 'Case #%d:' % (t+1)
    print solve(R, C, M)
