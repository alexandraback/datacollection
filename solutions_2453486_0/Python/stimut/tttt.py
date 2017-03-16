#!/usr/bin/env python

import sys

def memoize(func):
    cache = {}
    @wraps(func)
    def wrap(*args):
        if args not in cache:
            cache[args] = func(*args)
        return cache[args]
    return wrap


def read_ints():
    return [int(x) for x in sys.stdin.readline().split()]

def check_horiz(board):
    for row in board:
        target = row[0]
        if target == 'T':
            target = row[1]
        if target == '.':
            continue

        for ch in row:
            if ch != 'T' and ch != target:
                break
        else:
            return target

    return None

def check_vert(board):
    for col in range(len(board)):
        target = board[0][col]
        if target == 'T':
            target = board[1][col]
        if target == '.':
            continue

        for row in range(1, len(board)):
            if board[row][col] != 'T' and board[row][col] != target:
                break
        else:
            return target

    return None

def check_diag(board):
    target = board[0][0]
    if target == 'T':
        target = board[1][1]
    if target != '.':
        for idx in range(1, len(board)):
            if board[idx][idx] != 'T' and board[idx][idx] != target:
                break
        else:
            return target

    target = board[0][3]
    if target == 'T':
        target = board[1][2]
    if target != '.':
        for idx in range(1, len(board)):
            if board[idx][3-idx] != 'T' and board[idx][3-idx] != target:
                break
        else:
            return target

    return None

T = int(input())

for case in range(T):
    print("Case #", case+1, ": ", sep='', end='')

    board = []
    for _ in range(4):
        board.append(input())

    winner = check_horiz(board)
    if not winner:
        winner = check_vert(board)
    if not winner:
        winner = check_diag(board)
    if winner:
        print(winner, "won")
    else:
        if '.' in board[0] or '.' in board[1] or '.' in board[2] or '.' in board[3]:
            print("Game has not completed")
        else:
            print("Draw")

    # read blank line
    input()

