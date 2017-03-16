def iterbox():
    c = 0
    while True:
        x, y = (c, 0)
        while y < x:
            yield (x, y)
            y += 1
        yield (x, y)
        x -= 1
        while x >= 0:
            yield (x, y)
            x -= 1
        c += 1

def sweep(rows, cols, mines):
    # Create an empty grid (fill with mines first)
    grid = []
    for i in xrange(rows):
        grid.append(['*' for j in xrange(cols)])

    # Handle special cases
    # No spaces loses
    if rows*cols == mines:
        return False
    # Single empty space wins
    if rows*cols-1 == mines:
        grid[i][j] = 'c'
        return grid

    # Single row or column wins
    if rows == 1:
        for j in xrange(mines, cols):
            grid[0][j] = '.'
        grid[0][cols-1] = 'c'
        return grid
    if cols == 1:
        for i in xrange(mines, rows):
            grid[i][0] = '.'
        grid[rows-1][0] = 'c'
        return grid

    # Otherwise, grow a ring of blank spaces around the corder of the board
    blanks = rows*cols - mines
    # SPECIAL CASE blanks = 2 or 3
    if blanks in (2,3):
        return False

    # Try and find a rectangle that could enclose all blanks
    # such that the number of remaining tiles is not 1
    for nrows in xrange(2, rows+1):
        for ncols in xrange(2, cols+1):
            remain = blanks - (nrows*ncols)
            if remain < 0:
                break

            if remain > cols and remain > rows:
                continue
            if remain > nrows or remain > ncols:
                continue
            if remain >= rows and nrows == rows:
                continue
            if remain >= cols and ncols == cols:
                continue
            if remain == 1 and (nrows < 3 or ncols < 3):
                continue

            for i in xrange(nrows):
                for j in xrange(ncols):
                    grid[i][j] = '.'

            if remain:
                if i+1 == rows:
                    for i in xrange(remain):
                        grid[i][j+1] = '.'
                    if remain == 1:
                        grid[nrows-1][j] = '*'
                        grid[i+1][j+1] = '.'
                else:
                    for j in xrange(remain):
                        grid[i+1][j] = '.'
                    if remain == 1:
                        grid[i][ncols-1] = '*'
                        grid[i+1][j+1] = '.'

            grid[0][0] = 'c'
            return grid
    return False

def gen(limit):
    print limit
    c = 0
    for i, d in enumerate(iterbox()):
        rows, cols = d
        rows += 1
        cols += 1
        for j in xrange(rows*cols+1):
            print rows, cols, j
            c += 1
            if c > limit:
                break
        if c > limit:
            break


if __name__ == '__main__':
    count = int(raw_input())
    for i in xrange(count):
        rows, cols, mines = [int(x) for x in raw_input().strip().split()]
        res = sweep(rows, cols, mines)
        if not res:
            print "Case #%d:\nImpossible" % (i+1)
            continue
        else:
            print "Case #%d:" % (i+1)
            for row in res:
                print ''.join(row)
