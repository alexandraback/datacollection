#!/usr/bin/env python
#-*- coding:utf-8 -*-

from itertools import product
import sys

get_ints = lambda f:map(int, next(f).strip().split(' '))

def is_ok(N, M, lawn):
    status = [[False for _ in range(M)] for i in range(N)]
    Arr = sorted([(lawn[i][j], i, j) for i, j in product(range(N), range(M))])
    for height, i, j in Arr:
        if not status[i][j]:
            if all(lawn[i][y] <= height for y in range(M)):
                for y in range(M):
                    status[i][y] = True
            elif all(lawn[x][j] <= height for x in range(N)):
                for x in range(N):
                    status[x][j] = True
            else:
                return False
    return True

def get_input(f):
    T = int(next(f))
    for _ in range(T):
        N, M = get_ints(f)
        yield N, M, [get_ints(f) for _ in range(N)]

def main():
    for i, Input in enumerate(get_input(sys.stdin)):
        print "Case #{0}:".format(i + 1), "YES" if is_ok(*Input) else "NO"

if __name__ == "__main__":
    main()
