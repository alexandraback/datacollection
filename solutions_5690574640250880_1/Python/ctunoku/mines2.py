inf = 100000

def transpose(grid):
    if grid is False:
        return False

    gridt = [list() for _ in range(len(grid[0]))]
    for row in grid:
        for col in range(len(row)):
            gridt[col].append(row[col])
    return gridt

def one_grid(length, clear):
    return [[True] * clear + [False] * (length - clear)]

def two_grid(length, clear):
    if clear % 2 != 0:
        return False
    if clear == 2:
        return False

    row1 = one_grid(length, clear / 2)
    row2 = one_grid(length, clear / 2)
    return row1 + row2

def trim(r, c, to_trim):
    """Trims a block by TO_TRIM (adds that many mines).

    TO_TRIM < R
    """
    grid_row = [True] * c
    grid = [list(grid_row) for _ in range(r)]

    if to_trim == 0:
        return grid

    for trim in range(r - 2):
        grid[r - trim - 1][c - 1] = False
        to_trim -= 1
        if to_trim == 0:
            return grid

    grid[r - 1][c - 2] = False
    return grid

def solve_block(r, c, clear):
    """Solve a block of at least 3x3.
    """
    if clear in [2, 3, 5, 7]:
        return False
    if clear in [4, 6, 8, 9]:
        if clear == 4:
            grid = trim(2, 2, 0)
        elif clear == 6:
            grid = trim(2, 3, 0)
        elif clear == 8:
            grid = trim(3, 3, 1)
        else:
            grid = trim(3, 3, 0)
        pad_grid(r, c, grid)
        return grid

    for block_r in range(2, r + 1):
        for block_c in range(max(block_r, 4), c + 1):
            blocksize = block_r * block_c
            to_trim = blocksize - clear
            if to_trim < 0:
                continue
            if to_trim >= block_r:
                continue

            grid = trim(block_r, block_c, to_trim)
            pad_grid(r, c, grid)
            return grid

    return False

def pad_grid(r, c, grid):
    """Pads a grid with False values.
    """
    for row in grid:
        row += [False] * (c - len(row))
    for _ in range(r - len(grid)):
        grid.append([False] * c)

def grid_char(val):
    if val is True:
        return '.'
    elif val is False:
        return '*'
    else:
        return 'c'

def print_grid(grid):
    if grid is False:
        return "Impossible\n"

    result = ''
    grid[0][0] = 'c'
    for row in grid:
        line = ''.join(grid_char(v) for v in row)
        result += line + '\n'
    return result

def solve(r, c, clear):
    if clear == 0:
        return [[False] * c for _ in range(r)]
    if clear == 1:
        grid = [[False] * c for _ in range(r)]
        grid[0][0] = True
        return grid

    if r == 1:
        return one_grid(c, clear)
    if c == 1:
        return transpose(one_grid(r, clear))
    if r == 2:
        return two_grid(c, clear)
    if c == 2:
        return transpose(two_grid(r, clear))

    return solve_block(r, c, clear)

result = ''
with open('input.txt') as f:
    cases = int(f.readline()[:-1])

    for case in range(cases):
        case += 1

        line = f.readline()[:-1]
        r, c, m = line.split()
        r, c, m = int(r), int(c), int(m)
        if r > c:
            grid = transpose(solve(c, r, r * c - m))
        else:
            grid = solve(r, c, r * c - m)

        result += "Case #%s:\n" % case
        result += print_grid(grid)

with open('output.txt', 'w') as f:
    f.write(result)