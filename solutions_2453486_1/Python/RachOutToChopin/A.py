#!/usr/bin/python
import math
import string
import sys

FREE = 'T'
EMPTY = '.'

def isWinningFour(arr, c):
    for x in arr:
        if x != c and x != FREE:
            return False
    return True


def checkWin(board, c):
    for i in range(4):
        # Check i-th row and i-th column
        row = [ x for x in board[i]]
        col = [ x[i] for x in board]
        if isWinningFour(row, c) or isWinningFour(col, c):
            return True
    # Check diagonals
    d1 = [ board[j][j] for j in range(4) ]
    d2 = [ board[j][4-j-1] for j in range(4) ]
    return isWinningFour(d1, c) or isWinningFour(d2, c)

def checkOver(board):
    # Sufficient that there's nothing empty
    for row in board:
        for x in row:
            if x == EMPTY:
                return False
    return True

def solve(line):
    board = []
    for i in range(4):
        board.append(f.readline().strip())
    if checkWin(board, 'X'):
        return 'X won'
    if checkWin(board, 'O'):
        return 'O won'
    if checkOver(board):
        return 'Draw'
    return 'Game has not completed'

f = open(sys.argv[1])
NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    print "Case #%d: %s" % (qq+1, solve(f))
    f.readline()
