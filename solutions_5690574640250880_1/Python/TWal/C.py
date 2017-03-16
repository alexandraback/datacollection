import sys

def d(*args):
    sys.stderr.write(', '.join(map(str, args)) + "\n")

def printf(*args):
    print ''.join(map(str, args))

def int_input():
    return map(int, raw_input().split(' '))

def isPossible(r, c, m):
    size = r*c
    freeCells = size-m
    if freeCells == 1:
        return True

    if r == 1 or c == 1:
        return True

    if (r == 2 or c == 2):
        d(freeCells)
        return m%2 == 0 and freeCells != 2

    return freeCells >= 4 and freeCells != 5 and freeCells != 7

def solve(r, c, m):
    if isPossible(r, c, m):
        #grid = [['.'] * c] * r
        grid = map(lambda _: map(lambda _: '.', xrange(c)), xrange(r))
        grid[0][0] = 'c'
        if c == 1:
            for i in xrange(r - m, r):
                grid[i][0] = '*'
        elif r == 1:
            for i in xrange(c - m, c):
                grid[0][i] = '*'
        elif c == 2:
            for i in xrange(r - m/2, r):
                grid[i][0] = '*'
                grid[i][1] = '*'
            if r*c-m == 1:
                grid[0][1] = '*'
        elif r == 2:
            for i in xrange(c - m/2, c):
                grid[0][i] = '*'
                grid[1][i] = '*'
            if r*c-m == 1:
                grid[1][0] = '*'
        else:
            filled = 0
            currentRow = r-1
            while filled != m and currentRow != 2:
                maxInRow = c if r > 2 else c-2
                toFillInRow = min(m - filled, maxInRow)
                filled += toFillInRow
                for i in xrange(c - toFillInRow, c):
                    grid[currentRow][i] = '*'
                currentRow -= 1
            if filled == m and r > 3 and currentRow != r-1 and grid[currentRow+1][1] == '*' and grid[currentRow+1][0] == '.':
                grid[currentRow+1][1] = '.'
                grid[currentRow][c-1] = '*'
            currentCol = c-1
            while filled != m and currentCol != 1:
                maxInCol = 3 if currentCol != 0 else 1
                toFillInCol = min(m - filled, maxInCol)
                filled += toFillInCol
                for i in xrange(3 - toFillInCol, 3):
                    grid[i][currentCol] = '*'
                currentCol -= 1
            if currentCol != c-1 and grid[0][currentCol+1] == '.' and grid[1][currentCol+1] == '*':
                grid[1][currentCol+1] = '.'
                grid[2][currentCol] = '*'
            if filled != m:
                grid[2][0] = '*'
                grid[2][1] = '*'
                filled += 2
                if m != filled:
                    grid[0][1] = '*'
                    grid[1][1] = '*'
                    grid[1][0] = '*'

        if len(filter(lambda x: x == '*', "".join(map(lambda x: "".join(x), grid)))) != m:
            print "NO"
        return "\n" + "\n".join(map(lambda x: "".join(x), grid))
    else:
        return "\nImpossible"

def read_input():
    return tuple(int_input())

if __name__ == '__main__':
    for i in xrange(int(raw_input())):
        printf("Case #", i+1, ": ", str(solve(*read_input())))
