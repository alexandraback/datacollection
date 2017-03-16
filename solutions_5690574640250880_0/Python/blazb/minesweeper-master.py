import sys
import os
import numpy as np
from scipy.ndimage.morphology import distance_transform_cdt
from scipy.ndimage.morphology import binary_dilation, binary_erosion
from scipy import ndimage
from math import sqrt
from operator import mul
from bisect import bisect

def factors(n):
    return [i for i in range(1, n//2 + 1) if not n%i] + [n]

def count_factor(n):
    def aux(n):
        for x in range(2, n//2 + 1):
            if n % x == 0:
                return x
        return n

    factors = []
    while(n > 1):
        factor = aux(n)
        factors.append(factor)
        n /= factor
    return factors


def problem_specific_parser(src):
    return [int(e) for e in next(src).split(" ")]

struct2 = ndimage.generate_binary_structure(2, 2)
def is_valid(board):
    dt = distance_transform_cdt(board)
    mask = dt > 1
    covered = np.logical_not(binary_dilation(mask, structure=struct2))
    return np.sum(board * covered) == 0 and ndimage.label(mask)[1] == 1


def stringify_board(board):
    t = {0: '*', 1: '.', 2: '.', 3: 'c'}
    stringified_board = ['']

    dt = distance_transform_cdt(board)
    try:
        candidate = np.argwhere(dt > 1)[0]
        board[candidate[0], candidate[1]] = 3
    except IndexError:
        board[0, 0] = 3

    for l in board:
        stringified_board.append("".join([t[e] for e in l]))

    return "\n".join(stringified_board)


def is_valid_size(r, c, sr, sc):
    if r == 1:
        return  2 <= sc <= c and sr == 1
    if c == 1:
        return  2 <= sr <= r and sc == 1

    return 2 <= sr <= r and 2 <= sc <= c


def candidate_size(r, c, s):
    f = factors(s)

    for factor in f:
        sr = factor
        sc = s / sr

        if (is_valid_size(r, c, sr, sc)):
            yield sr, sc


def solve(data):
    r, c, m = data

    empty_spaces = int(r * c - m)
    true_empty_spaces = int(r * c - m)
    b = np.zeros((r, c))

    if m == 0:
        b[:, :] = 1
        return stringify_board(b)
    if empty_spaces == 1:
        b[:, :] = 0
        b[0, 0] = 3
        return stringify_board(b)


    while(empty_spaces <= r * c):
        for sr, sc in candidate_size(r, c, empty_spaces):
            b = np.zeros((r, c))
            if empty_spaces == true_empty_spaces:
                b[:sr, :sc] = 1

                return stringify_board(b)

            else:
                b[:sr, :sc] = 1
                sr = int(sr)
                sc = int(sc)
                candidates = [(0, e) for e in range(sc)]
                candidates +=[(sr - 1, e) for e in range(sc)]
                candidates +=[(e, 0) for e in range(sr)]
                candidates +=[(e, sc - 1) for e in range(sr)]
                emptspc = empty_spaces

                for cand in candidates:
                    if (b[cand[0], cand[1]]) == 0:
                        continue

                    b[cand[0], cand[1]] = 0
                    if is_valid(b):
                        emptspc -= 1
                        if emptspc == true_empty_spaces:
                            return stringify_board(b)
                    else:
                        b[cand[0], cand[1]] = 1


        empty_spaces += 1
    return "\nImpossible"


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
