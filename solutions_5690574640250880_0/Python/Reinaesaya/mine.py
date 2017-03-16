# Sean Liu
# Minesweeper

def ones(R, C, M, board):
    num = M
    for x in range(R):
        for y in range(C):
            if num > 0:
                board[x][y] = '*'
                num -= 1
            else:
                break

def check(rows, columns, mines):
    maxim = (rows - 2)*(columns - 2)
    if mines <= maxim:
        return 1
    return 0

def fillin(R, C, row, column, mines, board):
    num = mines
    for x in range(row, R-2):
        for y in range(column, C-2):
            if num > 0:
                board[x][y] = '*'
                num -= 1
            else:
                break

def notone(R, C, row, column, mines, board):
    #base case
    if ((R-row == 2) and (C-column == 2)):
        if mines == 0:
            return 1
        elif mines == 3:
            board[row][column] = '*'
            board[row+1][column] = '*'
            board[row][column+1] = '*'
            return 1
        return 0 # Impossible
    elif ( R-row > C-column ):
        if check(R-row, C-column, mines):
            fillin(R, C, row, column, mines, board)
            return 1
        else:
            if mines < C-column:
                return 0
            for y in range(len(board[row])):
                board[row][y] = '*'
            return notone(R, C, row+1, column, mines-(C-column), board)
    else:
        if check(R-row, C-column, mines):
            fillin(R, C, row, column, mines, board)
            return 1
        else:
            if mines < R-row:
                return 0
            for x in range(R):
                board[x][column] = '*'
            return notone(R, C, row, column+1, mines-(R-row), board)


f = open("C-small-attempt1.in", "r")
g = open("output.txt", "w")

T = int(f.readline())

for i in range(T):
    g.write("Case #{}:\n".format(i+1))
    
    line = f.readline().split()
    R = int(line[0])
    C = int(line[1])
    M = int(line[2])

    board = [ ['.' for column in range(C)] for row in range(R) ]
    board[R-1][C-1] = 'c'

    if ((R==1) or (C==1)):
        ones(R, C, M, board)

    else:
        result = notone(R, C, 0, 0, M, board)
        if result == 0:
            g.write("Impossible\n")
            continue
    for i in range(len(board)):
        g.write(''.join(board[i]))
        g.write('\n')

f.close()
g.close()
