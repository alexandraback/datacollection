def solve(grid):
    if has_won('X', grid):
        return 'X won'
    elif has_won('O', grid):
        return 'O won'
    elif any(['.' in line for line in grid]):
        return 'Game has not completed'
    else:
        return 'Draw'


def has_won(who, grid):
    range4 = range(4)
    def ok(x, y, dx, dy):
        while x in range4 and y in range4: 
            if grid[y][x] not in (who, 'T'):
                return False
            x, y = x + dx, y + dy
        return True

    for start in range4:
        if ok(start, 0, 0, 1) or ok(0, start, 1, 0):
            return True

    return ok(0, 0, 1, 1) or ok(0, 3, 1, -1)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        grid = [input() for r in range(4)]
        input()
        print('Case #{}: {}'.format(t + 1, solve(grid)))
