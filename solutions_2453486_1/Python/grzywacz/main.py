#!/usr/bin/env python

import sys

test_cases = []
input_file = open(sys.argv[1])
number_of_cases = int(input_file.next())

def read_board(input_file):
    rows = []
    for _ in xrange(4):
        rows.append(input_file.next().strip())
    return rows

def transposed(board):
    t = []
    for col in xrange(4):
        column = [board[r][col] for r in xrange(4)]
        t.append("".join(column))
    return t

def solve_rows(board):
    for row in board:
        for char in ("X", "O"):
            if all([c == char for c in row]):
                return "%s won" % (char, )

def solve_cols(board):
    return solve_rows(transposed(board))

def solve_diagonals(board):
    first, second = [], []
    for x in xrange(4):
        first.append(board[x][x])
        second.append(board[3 - x][x])

    for diagonal in (first, second):
        for ch in ('O', 'X'):
            if all([c == ch for c in diagonal]):
                return "%s won" % (c, )

def replaced(board, t_to_ch):
    nb = []
    for row in board:
        nb.append(row.replace('T',  t_to_ch))
    return nb

def in_progress(board):
    for row in board:
        if '.' in row: return True
    return False

def solve(board):
    boards = (replaced(board, 'X'), replaced(board, 'O'))
    for method in [solve_rows, solve_cols, solve_diagonals]:
        for board in boards:
            s = method(board)
            if s:
                return s

    if in_progress(board):
        return "Game has not completed"

    return "Draw"

for case_no in xrange(number_of_cases):
    board = read_board(input_file)
    solution = solve(board)
    print "Case #%d: %s" % (case_no + 1, solution)
    if case_no < number_of_cases - 1:
        input_file.next()
