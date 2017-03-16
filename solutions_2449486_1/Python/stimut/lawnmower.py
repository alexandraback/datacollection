#!/usr/bin/env python

# Alg: For each square, if both vertically and horizontally there
#      exists a squre with a higher height, then the pattern is not possible.

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

# Pre-condition: lawn at least 2x2
def test_lawn(lawn, N, M):
    for row in range(N):
        for col in range(M):
            height = lawn[row][col]

            bigger_vert = False
            for above in range(row):
                if lawn[above][col] > height:
                    bigger_vert = True
                    break
            else:
                for below in range(row+1, N):
                    if lawn[below][col] > height:
                        bigger_vert = True
                        break

            bigger_horiz = False
            for left in range(col):
                if lawn[row][left] > height:
                    bigger_horiz = True
                    break
            else:
                for right in range(col+1, M):
                    if lawn[row][right] > height:
                        bigger_horiz = True
                        break

            if bigger_vert and bigger_horiz:
                return False

    return True

T = int(input())

for case in range(T):
    print("Case #", case+1, ": ", sep='', end='')
    N, M = read_ints()
    lawn = []
    for _ in range(N):
        lawn.append(read_ints())

    if N == 1 or M == 1:
        print("YES")
    else:
        if test_lawn(lawn, N, M):
            print("YES")
        else:
            print("NO")

