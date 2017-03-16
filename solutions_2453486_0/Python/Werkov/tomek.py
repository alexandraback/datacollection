#!/usr/bin/env python3

import sys

N = 4

def eval(i):
    # load
    grid = []
    for row in range(N):
        grid.append(sys.stdin.readline().strip())
    sys.stdin.readline()

    # eval
    rows = [N*[0] for _ in range(2)]
    cols = [N*[0] for _ in range(2)]
    diags = [2*[0] for _ in range(2)]
    empty = False

    for r, row in enumerate(grid):
        for c, char in enumerate(row):
            diagA = 0
            diagB = 0
            if c == r:
                diagA = 1
            if c == N - r - 1:
                diagB = 1

            if char == 'O' or char == 'T':
                rows[0][r] += 1
                cols[0][c] += 1
                diags[0][0] += diagA
                diags[0][1] += diagB
            if char == 'X' or char == 'T':
                rows[1][r] += 1
                cols[1][c] += 1
                diags[1][0] += diagA
                diags[1][1] += diagB
            if char == '.':
                empty = True

    # conclusion
    row_scores = [max(scores) for scores in rows]
    col_scores = [max(scores) for scores in cols]
    diag_scores = [max(scores) for scores in diags]

    if row_scores[0] == N or col_scores[0] == N or diag_scores[0] == N:
        print("Case #{}: O won".format(i))
    elif row_scores[1] == N or col_scores[1] == N or diag_scores[1] == N:
        print("Case #{}: X won".format(i))
    elif empty:
        print("Case #{}: Game has not completed".format(i))
    else:
        print("Case #{}: Draw".format(i))

l = int(sys.stdin.readline().strip())

for i in range(l):
    eval(i+1)

