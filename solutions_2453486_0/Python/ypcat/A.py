#!/usr/bin/python

import sys

def main():
    T = int(sys.stdin.readline())
    for case in range(1, T + 1):
        result = "Game has not completed"
        board = [sys.stdin.readline() for line in range(5)]
        lines = []
        lines += [[board[i][j] for i in range(4)] for j in range(4)]
        lines += [[board[j][i] for i in range(4)] for j in range(4)]
        lines += [[board[i][i] for i in range(4)]]
        lines += [[board[i][3 - i] for i in range(4)]]
        if any(all(t in 'XT' for t in line) for line in lines):
            result = "X won"
        elif any(all(t in 'OT' for t in line) for line in lines):
            result = "O won"
        elif all('.' not in line for line in board):
            result = "Draw"
        print "Case #%d: %s" % (case, result)

if __name__ == '__main__':
    main()

