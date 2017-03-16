def solve(R, C, grid):
    row_max = [max(row) for row in grid]
    col_max = [max([grid[r][c] for r in range(R)])
               for c in range(C)]

    for r in range(R):
        for c in range(C):
            if grid[r][c] != row_max[r] and grid[r][c] != col_max[c]:
                return 'NO'

    return 'YES'


if __name__ == '__main__':
    T = int(input())
    get_row = lambda: [int(k) for k in input().split()]
    for t in range(T):
        R, C = get_row()
        grid = [get_row() for row in range(R)]
        print('Case #{}: {}'.format(t + 1, solve(R, C, grid)))
