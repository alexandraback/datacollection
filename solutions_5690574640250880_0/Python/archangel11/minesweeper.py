Impossible = "Impossible"

def solve(f):
    rows, cols, mines = map(int, f.readline().split())
    #raw_input()
    #print rows, cols, mines

    output = Impossible
    grid = [["." for j in xrange(cols)] for i in xrange(rows)]

    def sub(r, c, m):
        if mines == cols * rows - 1:
            for ri in range(rows):
                for ci in range(cols):
                    grid[ri][ci] = "*"
            grid[0][0] = "c"
            return True
        if m == 0:
            grid[0][0] = "c"
            return True
        if rows == 1:
            grid[0][0] = "c"
            for ci in range(cols-m,cols):
                grid[0][ci] = "*"
            return True
        if cols == 1:
            grid[0][0] = "c"
            for ri in range(rows-m,rows):
                grid[ri][0] = "*"
            return True

        if r < 3 or c < 3:
            if m == 1:
                return False
            if r < 3 and c < 3:
                return False

        #print "---------------"
        #print "\n".join(map("".join, grid))
        if r <= c:
            if m%r == 0:
                for i in xrange(r):
                    grid[i][c-1] = "*"
                return sub(r, c-1, m-r)
            if r > 2 and (m >= c or c-m > 1):
                for i in xrange(max(c-m,0), c):
                    grid[r-1][i] = "*"
                    m -= 1
                return sub(r-1, c, m)
            elif m >= r:
                for i in xrange(r):
                    grid[i][c-1] = "*"
                return sub(r, c-1, m-r)
            elif r > 3 and c-m == 1:
                for i in xrange(2,c):
                    grid[r-1][i] = "*"
                grid[r-2][c-1] = "*"
                grid[0][0] = "c"
                return True
        else:
            if m%c == 0:
                for i in xrange(c):
                    grid[r-1][i] = "*"
                return sub(r-1, c, m-c)
            if c > 2 and (m >= r or r-m > 1):
                for i in xrange(max(r-m,0), r):
                    grid[i][c-1] = "*"
                    m -= 1
                return sub(r, c-1, m)
            elif m >= c:
                for i in xrange(c):
                    grid[r-1][i] = "*"
                return sub(r-1, c, m-c)
            elif c > 3 and r-m == 1:
                for i in xrange(2,r):
                    grid[i][c-1] = "*"
                grid[r-1][c-2] = "*"
                grid[0][0] = "c"
                return True

    if sub(rows, cols, mines):
        output = "\n".join(map("".join, grid))

    return "\n" + output

