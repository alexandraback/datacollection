#!/usr/bin/python

import sys

BOMB, EMPTY, CLICK = '*', '.', 'c'

def transpose(board):
    tboard = [[EMPTY]*len(board) for i in range(0, len(board[0]))]
    for i in range(0, len(board)):
        for j in range(0, len(board[i])):
            tboard[j][i] = board[i][j]
    return tboard

def to_string(board):
    return '\n'.join(''.join(row) for row in board)

def fill_horizontally(R, C, M, board):
    point = (0,0)
    while (M > 0):
        board[point[0]][point[1]] = BOMB
        M -= 1
        if point[1] == C-1 or (point[1] == C-3 and M == 1):
            point = (point[0] + 1, 0)
        else:
            point = (point[0], point[1] + 1)
    return board

def fill_rest(R, C, M, board):
    col = 0
    while M > 0:
        M -= 2
        board[R-2][col], board[R-1][col] = BOMB, BOMB
        col += 1
    return board

def check_possibility(R, C, M, board):
    board[R-1][C-1] = CLICK
    if M == 0: return (True, board)
    if M == R*C-1: 
        board = [[BOMB]*C for i in range(0,R)]
        board[R-1][C-1] = CLICK
        return (True, board)
    if M >= R*C-3 and C > 1 and R > 1: return (False, board)
    if R == 1 or C == 1:
        board = [BOMB]*M + [EMPTY]*(R*C-M-1) + [CLICK]
        return (True, board) if C == 1 else (True, transpose(board))
    
    transposed = False
    if (R > 2 and R < C) or C == 2:
        board = transpose(board)
        R, C = C, R
        transposed = True    
    bombs_left = M
    if R > 2:
        board = fill_horizontally(R, C, min(M, (R-2)*C - 2), board)
        bombs_left -= (R-2)*C - 2

    if bombs_left <= 0 or bombs_left % 2 == 0:
        if bombs_left > 0:
            if R > 2:
                board[R-3][C-2], board[R-3][C-1] = BOMB, BOMB
                bombs_left -= 2
            board = fill_rest(R, C, bombs_left, board)
        return (True, board) if not transposed else (True, transpose(board))
    elif bombs_left > 0 and bombs_left % 2 == 1 and bombs_left + 1 <= (C-3)*2 and R > 2 and C > 3:
        board[R-3][C-3] = EMPTY
        board = fill_rest(R, C, bombs_left+1, board)
        return (True, board) if not transposed else (True, transpose(board))
    return (False, board)

def solve_test_case(R, C, M):
    board = [[EMPTY]*C for i in range(0, R)]
    possible, board = check_possibility(R, C, M, board)
    return 'Impossible' if not possible else to_string(board)

def main():
    f = open(sys.argv[1], 'r')
    n = int(f.readline().strip())
    for i in range(1,n+1):
        R, C, M = (int(d) for d in f.readline().strip().split(' '))
        print 'Case #%d:\n%s' % (i, solve_test_case(R, C, M))

if __name__ == '__main__':
    main()
