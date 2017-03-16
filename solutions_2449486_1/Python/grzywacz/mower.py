#!/usr/bin/env python

import sys

input_file = open(sys.argv[1])
no_cases = int(input_file.next())

def solve(board, N, M):
    for y, row in enumerate(board):
        for x, col in enumerate(row):
            ok = True
            for nx in xrange(M):
                if board[y][nx] > col:
                    ok = False
                    break
            if not ok:
                for ny in xrange(N):
                    if board[ny][x] > col:
                        return "NO"
    return "YES"

for case_no in xrange(no_cases):
    N, M = [int(i) for i in input_file.next().strip().split(' ')]
    board = []
    for _ in xrange(N):
        board.append([int(i) for i in input_file.next().strip().split(' ')])

    answer = solve(board, N, M)
    print "Case #%d: %s" % (case_no + 1, answer)
