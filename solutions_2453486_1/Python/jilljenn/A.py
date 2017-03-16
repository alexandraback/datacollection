def r(grid):
    tgrid = [''.join(grid[j][i] for j in range(4)) for i in range(4)]
    diags = [''.join(grid[i][i] for i in range(4))] + [''.join(grid[i][3 - i] for i in range(4))]
    x = 'XXXX' in [_.replace('T', 'X') for _ in grid + tgrid + diags]
    o = 'OOOO' in [_.replace('T', 'O') for _ in grid + tgrid + diags]
    if not x and not o:
        if any(['.' in _ for _ in grid]):
            return 'Game has not completed'
        return 'Draw'
    if x:
        return 'X won'
    return 'O won'

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        grid = [raw_input() for _ in range(4)]
        raw_input()
        print 'Case #%d: %s' % (i + 1, r(grid))
