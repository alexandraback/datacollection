#!/usr/bin/python
import sys
import math
import itertools
import copy

def is_possible(R, C, M):
    if R > C:
        R, C = C, R

    #always more columns than rows (or equal)
    if R == 1:
        return C - 2 >= M
    elif R >= 2:
        return R * C >= 4 + M


def build_board(R, C, M):
    remaining = M
    board = [['.' for x in xrange(C)] for x in xrange(R)]
    board[-1][-1] = 'c'

    full_row_index = 0
    while remaining > 0 and full_row_index < R - 3:
        #count row spaces
        empty = 0
        for c in xrange(C):
            if board[full_row_index][c] == '.':
                empty += 1

        if remaining >= empty:
            for c in xrange(C):
                if board[full_row_index][c] == '.':
                    board[full_row_index][c] = '*'
                    remaining -= 1

        full_row_index += 1

    full_col_index = 0
    while remaining > 0 and full_col_index < C - 3:
        #count row spaces
        empty = 0
        for r in xrange(R):
            if board[r][full_col_index] == '.':
                empty += 1

        if remaining >= empty:
            for r in xrange(R):
                if board[r][full_col_index] == '.':
                    board[r][full_col_index] = '*'
                    remaining -= 1

        full_col_index += 1

    if remaining > 0:
        cells = []
        for r in xrange(R):
            for c in xrange(C):
                if board[r][c] == '.' and (r != R - 1 or c != C - 1):
                    cells.append((r, c))

        board[-1][-1] = 'c'

        #print "brute", len(cells)
        #print "\n\n"
        #print_board(board)
        #print "\n\n"
        #print remaining
        board = build_board_brute_cells(R, C, remaining, M, board, cells)
    return board


def build_board_brute_cells(R, C, remaining, M, base_board, cells):
    if M + 1 > R * C:
        return None

    all_combinations = itertools.combinations(cells, remaining)
    for board_setup in all_combinations:
        board = copy.deepcopy(base_board)

        for (row, col) in board_setup:
            board[row][col] = '*'

        #print "\n\n"
        #print_board(board)
        #print "\n\n"

        if check_board(board, R, C, M):
            return board

    return None

def print_board(board):
    for b in board:
        print ''.join(b)


def get_neighborhood(R, C, row, col):
    """
    B A H
    C x G
    D E F
    """
    result = [(row, col)]
    if row > 0:
        result.append((row - 1, col))  # A
    if row > 0 and col > 0:
        result.append((row - 1, col - 1))  # B
    if col > 0:
        result.append((row, col - 1))  # C
    if row < R - 1 and col > 0:
        result.append((row + 1, col - 1))  # D
    if row < R - 1:
        result.append((row + 1, col))  # E
    if row < R - 1 and col < C - 1:
        result.append((row + 1, col+1))  # F
    if col < C - 1:
        result.append((row, col+1))  # G
    if row > 0 and col < C - 1:
        result.append((row - 1, col+1))  # H
    return result


def is_zero_bombs(board, neighborhood):
    zero = True
    for (row, col) in neighborhood:
        if board[row][col] == '*':
            zero = False
            break
    return zero


def check_board(board, R, C, M):
    visited = set()

    #search for initial
    row = None
    col = None
    for r in xrange(R):
        for c in xrange(C):
            if board[r][c] == 'c':
                row = r
                col = c
                break

    to_visit = set()
    to_visit.add((row, col))

    while len(to_visit) > 0:
        (row, col) = to_visit.pop()
        if board[row][col] != '*':
            neighbors = get_neighborhood(R, C, row, col)
            if is_zero_bombs(board, neighbors):
                #visit all neighbors
                for n in neighbors:
                    if n not in visited:
                        to_visit.add(n)
        visited.add((row, col))

    return len(visited) + M == R * C


def main():
    tests = int(sys.stdin.readline())

    for test in xrange(tests):
        parts = sys.stdin.readline().split(" ")
        R = int(parts[0])
        C = int(parts[1])
        M = int(parts[2])

        print "Case #%d:" % (test + 1)
        #print R, C, M

        #if R * C < 100:
         #   board = build_board_brute(R, C, M)
        #else:
         #   board = build_board(R, C, M)

        board = build_board(R, C, M)
        if board and check_board(board, R, C, M):
            print_board(board)
        else:
            print "Impossible"


main()
