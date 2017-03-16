#!/usr/bin/env python


def read():
    row, col = map(int, raw_input().split())
    board = []
    for i in range(row):
        board.append(map(int, raw_input().split()))
    return board


def work(board, cases):
    row, col = len(board), len(board[0])
    cur = [[100 for j in range(col)] for i in range(col)]

    print "Case #%d:" % cases,

    for r in range(row):
        for c in range(col):
            if any([board[rr][c] > board[r][c] for rr in range(row)]) and \
               any([board[r][cc] > board[r][c] for cc in range(col)]):
                print "NO"
                return

    print "YES"


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(read(), i + 1)
