#!/usr/bin/env python3

import sys
rl = lambda: sys.stdin.readline()
T = int(rl())

# left-up corner = white square


def foo(X, R, C):
    if X < 0 or R < 0 or C < 0:
        return False
    squares = R * C
    white_squares = (R // 2) * C
    if R % 2 != 0:
        white_squares += (C // 2) + (C % 2)
    black_squares = squares - white_squares
    if X >= 7:
        return False
    if squares % X != 0:
        return False
    if (X % 2 == 0) and (white_squares != black_squares):
        return False
    if X == 1 or X == 2:
        return True
    if X == 3:
        if R <= 1 or C <= 1:
            return False
        return True
    if X == 4:
        if R <= 3 and C <= 3:
            return False
        if squares == 12 or squares == 16:
            return True
        # TODO
    # TODO

def solve(casei):
    line = rl().split()
    X = int(line[0])
    R = int(line[1])
    C = int(line[2])
    ans = foo(X, R, C)
    winner = ""
    if ans:
        winner = "GABRIEL"
    else:
        winner = "RICHARD"
    print("Case #{}: {}".format(casei, winner))

for i in range(1, T+1):
    solve(i)
