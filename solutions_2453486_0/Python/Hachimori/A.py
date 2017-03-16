#!/usr/bin/env python


def read():
    board = ""
    for i in range(4):
        board += raw_input()+','
    board += ",,,,,"
    raw_input()
    return board


def work(board, cases):
    print "Case #%d:" % cases,
    
    for bgn in range(len(board)):
        for mov in [1,4,5,6]:
            cntO = 0
            cntX = 0
            cur = bgn
            while board[cur] != ',':
                if board[cur] == 'O' or board[cur] == 'T':
                    cntO += 1
                if board[cur] == 'X' or board[cur] == 'T':
                    cntX += 1
                cur += mov

            if cntO == 4:
                print "O won"
                return

            if cntX == 4:
                print "X won"
                return

    if '.' in board:
        print "Game has not completed"
    else:
        print "Draw"


if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(read(), i + 1)
