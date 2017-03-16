import argparse
import collections
import fractions
import functools
import itertools
import math
import operator

from sys import exit, stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip()

def parse():
    return read_ints()

# def solve_inner(moves, x, y, target_x, target_y):
#     jump_len = len(moves) + 1
#     if x == target_x:
#         if y == target_y:
#             return moves
#         else:
#             r = solve_inner(moves + ["N"], x, y + jump_len, target_x, target_y)
#             if r:
#                 return r
#             r = solve_inner(moves + ["S"], x, y - jump_len, target_x, target_y)
#             if r:
#                 return r
#     else:
#         r = solve_inner(moves + ["E"], x + jump_len, y, target_x, target_y)
#         if r:
#             return r
#         r = solve_inner(moves + ["W"], x - jump_len, y, target_x, target_y)
#         if r:
#             return r
#         if y != target_y:
#             r = solve_inner(moves + ["N"], x, y + jump_len, target_x, target_y)
#             if r:
#                 return r
#             r = solve_inner(moves + ["S"], x, y - jump_len, target_x, target_y)
#             if r:
#                 return r

def solve(x, y):
    moves = []
    for i in range(abs(x)):
        moves.extend(["W", "E"] if x > 0 else ["E", "W"])
    for i in range(abs(y)):
        moves.extend(["S", "N"] if y > 0 else ["N", "S"])
    return "".join(moves)

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("-m", "--multi", help="turn on multiprocessing", action="store_true")
    args = parser.parse_args()
    
    with open("out.txt", "w") as f:
        if args.multi:
            pool = Pool()
            iter = pool.imap(solve_star, (parse() for i in range(read_int())))
            for i, result in enumerate(iter):
                s = "Case #{}: {}".format(i + 1, result)
                print(s)
                f.write(s + "\n")
        
        else:
            for i in range(read_int()):
                s = "Case #{}: {}".format(i + 1, solve(*parse()))
                print(s)
                f.write(s + "\n")