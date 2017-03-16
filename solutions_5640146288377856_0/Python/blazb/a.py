import sys
import os
import numpy as np
import math


def problem_specific_parser(src):
    return [int(e) for e in next(src).split(' ')]


def solve(data):
    rows, cols, w = data
    board = np.zeros((rows, cols))

    nsteps = 0

    #for r in range(0, rows, w):
        #for c in range(0, cols, w):
            #board[r, c] = 1
    npercol = int(math.ceil(cols / float(w)))
    nsteps = rows * npercol + w - 1
    return nsteps


def parse(src):
    lines = iter(src.split(os.linesep))
    nproblems = int(next(lines))

    for problem in range(nproblems):
        yield problem_specific_parser(lines)


def main():
    src = sys.stdin.read()
    for i, data in enumerate(parse(src)):
        print("Case #{0}: {1}".format(i + 1, solve(data)))

    
if __name__ == '__main__':
    main()
