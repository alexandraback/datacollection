import sys

def fillRow(data, row):
    for i in range(len(data[row])):
        data[row][i] = '*'

def fillCol(data, col):
    for i in data:
        i[col] = '*'

def fill(data, row, col):
    data[row][col] = '*'

def printSolution(data):
    return '\n'.join([''.join(i) for i in data])

def solve():
    row, col, mines = map(int, sys.stdin.readline().split())
    data = [['.'] * col for i in range(row)]
    data[0][0] = 'c'
    row -= 1
    col -= 1
    if row == 0:
        while mines:
            fill(data, row, col)
            col -= 1
            mines -= 1
        return printSolution(data)
    elif col == 0:
        while mines:
            fill(data, row, col)
            row -= 1
            mines -= 1
        return printSolution(data)
    else:
        while row < mines or col < mines:
            if col < row:
                fillRow(data, row)
                row -= 1
                mines -= col + 1
            else:
                fillCol(data, col)
                col -= 1
                mines -= row + 1
        if not mines:
            if 1 <= row and 1 <= col or row == 0 and col == 0:
                return printSolution(data)
            else:
                return 'Impossible'
        else:
            if col < row:
                i = row
                while 1 < i and mines:
                    fill(data, i, col)
                    mines -= 1
                    i -= 1
                assert(mines == 0)
                row -= 1
                col -= 1
                if 1 <= row and 1 <= col:
                    return printSolution(data)
                else:
                    return 'Impossible'
            else:
                i = col
                while 1 < i and mines:
                    fill(data, row, i)
                    mines -= 1
                    i -= 1
                if mines:
                    assert(mines == 1)
                    row -= 1
                    fill(data, row, col)
                row -= 1
                col -= 1
                if 1 <= row and 1 <= col:
                    return printSolution(data)
                else:
                    return 'Impossible'

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d:' % (i + 1))
        print(solve())
