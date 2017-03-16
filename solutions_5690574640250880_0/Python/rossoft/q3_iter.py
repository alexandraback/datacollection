#!/usr/bin/python
import sys
import math
import itertools


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


def build_board(R, C, M):
    cells = []
    for r in xrange(R):
        for c in xrange(C):
            cells.append((r, c))

    if M + 1 > R * C:
        return None

    all_combinations = itertools.combinations(cells, M + 1)
    for board_setup in all_combinations:
        (row, col) = board_setup[0]

        board = [['.' for x in xrange(C)] for x in xrange(R)]
        board[row][col] = 'c'
        for (row, col) in board_setup[1:]:
            board[row][col] = '*'

        if check_board(board, R, C, M):
            return board

    return None

def main():
    tests = int(sys.stdin.readline())

    for test in xrange(tests):
        parts = sys.stdin.readline().split(" ")
        R = int(parts[0])
        C = int(parts[1])
        M = int(parts[2])

        print "Case #%d:" % (test + 1)

        #else:
        board = build_board(R, C, M)
        if board:
            print_board(board)
        else:
            print "Impossible"


main()
