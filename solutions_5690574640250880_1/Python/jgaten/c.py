#!/usr/bin/env python

import sys

IMPOSSIBLE = []

def transpose(grid):
    return map(list, zip(*grid))

def find_grid(R, C, M):
    """Return a grid of a solution, if one exists, otherwise []

    Observations:
    * WLOG, C <= R (otherwise, take the transpose of a solution)
    * Trivial cases are:
      - M = 0 or  M = RC - 1
      - C = 1
      - (R, C) = (2, 2)
      - (R, C, M) = (3, 3, 2)
      - (C, M) = (2, 1)
    * If M >= C >= 2 and R >= 3, we can add a row of C mines to the bottom and consider M'=M-C, R'=R-1
    * The remaining cases are M <= R-2, and M + 1 == R == C >= 4, which are both solvable
    """
    # Take care of simple cases
    if M == 0:
        grid = [['.' for c in xrange(C)] for r in xrange(R)]
        grid[0][0] = 'c'
        return grid
    elif M == R * C - 1:
        grid = [['*' for c in xrange(C)] for r in xrange(R)]
        grid[0][0] = 'c'
        return grid
    elif C > R:
        return transpose(find_grid(C, R, M))
    elif C == 1:
        return [['c']] + [['.'] for i in xrange(R-M-1)] + [['*'] for i in xrange(M)]
    elif (R, C) == (2, 2) or (R, C, M) == (3, 3, 2) or (C, M) == (2, 1):
        return IMPOSSIBLE

    assert 2 <= C <= R >= 3, "R={} C={} M={}".format(R, C, M)

    if M >= C:
        s = find_grid(R-1, C, M-C)
        return s and s + [['*' for c in xrange(C)]]
    elif M <= R-2 and C >= 3:
        grid = [['.' for c in xrange(C)] for r in xrange(R)]
        grid[0][0] = 'c'
        for i in xrange(M):
            grid[R-i-1][C-1] = '*'
        return grid
    elif M + 1 == R == C >= 4:
        grid = [['.' for c in xrange(C)] for r in xrange(R)]
        grid[0][0] = 'c'
        grid[R-1][C-2] = '*'
        for i in xrange(M-1):
            grid[R-i-1][C-1] = '*'
        return grid

    assert False, "R={} C={} M={}".format(R, C, M)

def solve(R, C, M):
    soln = find_grid(R, C, M)
    if soln == IMPOSSIBLE:
        return "Impossible"
    else:
        return '\n'.join(''.join(row) for row in soln)

if __name__ == '__main__':
    fin = open(sys.argv[1], 'rU') if sys.argv[1:] else sys.stdin
    fout = open(sys.argv[2], 'w') if sys.argv[2:] else sys.stdout
    with fin, fout:
        T = int(fin.readline())
        for case in xrange(1, T+1):
            r, c, m = map(int, fin.readline().split())
            soln = solve(r, c, m)
            print >> fout, "Case #{0}:\n{1}".format(case, soln)

