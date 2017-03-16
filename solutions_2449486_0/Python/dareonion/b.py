#!/usr/bin/env python
import sys

def can_mow(grid, row_mins, col_mins):
    N = len(grid)
    M = len(grid[0])
    for _row in xrange(N):
        for _col in xrange(M):
            if grid[_row][_col] < min(row_mins[_row], col_mins[_col]):
                return "NO"
    return "YES"

def main():
    assert len(sys.argv) == 3, str(sys.argv)
    in_name = sys.argv[1]
    out_name = sys.argv[2]
    with open(in_name) as f, open(out_name, 'w') as g:
        T = int(f.readline().strip()) # number of cases
        for test_num in xrange(T):
            N, M = map(int, f.readline().strip().split())
            grid = []
            for _row in xrange(N):
                grid.append(map(int, f.readline().strip().split()))

            row_mins = [max(row) for row in grid]
            col_mins = [max(col) for col in zip(*grid)]

            g.write("Case #%s: %s\n" % (
                test_num+1,
                can_mow(grid, row_mins, col_mins)))
    return 0

if __name__ == "__main__":
    status = main()
    sys.exit(status)
