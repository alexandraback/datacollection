def parse(f):
    ncase = int(f.readline())
    for i in range(ncase):
        print "Case #%d:"%(i+1)
        line = map(int, f.readline().strip().split())
        sol = solve_case(*line)
        r = grid_repr(sol)
        print r

def transpose(grid):
    if grid is None: return None
    r = len(grid)
    c = len(grid[0])
    return [[grid[i][j] for i in range(r)] for j in range(c)]

def grid_repr(grid):
    if not grid:
        return "Impossible"
    return '\n'.join(''.join(row) for row in grid)

def solve_case(R, C, M):
    if C < R:
        return transpose(solve_case(C, R, M))
    V = R*C - M
    if V == 1:
        grid = [['*' for c in range(C)] for r in range(R)]
        grid[0][0] = 'c'
        return grid
    if R == 1:
        return [ 'c' + '.'*(C - M - 1) + '*'*M ]
    if V < 9:
        if V not in [4, 6, 8]:
            return None
    if R == 2:
        if M % 2:
            return None
        else:
            return [
                'c' + '.'*(C - M/2 - 1) + '*'*(M/2),
                '.'*(C - M/2) + '*'*(M/2)
                ]
    if R == 3:
        grid = [['*' for c in range(C)] for r in range(R)]
        for i in range((V+2) / 3):
            grid[0][i] = '.'
            grid[1][i] = '.'
        for i in range((V+2) / 3 - (M % 3)):
            grid[2][i] = '.'
    if R >= 4:
        if M < C:
            grid = [['.' for c in range(C)] for r in range(R)]
            if M <= C-2:
                for i in range(M):
                    grid[-1][i] = '*'
            if M == C-1:
                for i in range(C-2):
                    grid[-1][i] = '*'
                grid[-2][0] = '*'
        if M >= C:
            grid = solve_case(R-1, C, M-C) + [['*' for c in range(C)]]
    grid[0][0] = 'c'
    return grid

import sys
parse(sys.stdin)
