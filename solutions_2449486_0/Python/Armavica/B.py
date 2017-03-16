#! /usr/bin/python -tt

def solve(grid):
    max_rows = [max(row) for row in grid]
    max_cols = [max(col) for col in zip(*grid)]
    for r in xrange(len(grid)):
        for c in xrange(len(grid[0])):
            if grid[r][c] < max_rows[r] and grid[r][c] < max_cols[c]:
                return "NO"
    return "YES"

n = input()
for problem_nb in xrange(n):
    (N, M) = tuple((int(nb) for nb in raw_input().split(" ")))
    grid = []
    for row in range(N):
        grid.append([int(nb) for nb in raw_input().split(" ")])
    print "Case #"+str(problem_nb + 1)+":", solve(grid)
