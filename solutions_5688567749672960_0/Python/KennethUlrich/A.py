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

def read_floats():
    return [float(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip().split()

def parse():
    return [read_int()]

def reverse(n):
    s = str(n)[::-1]
    return int(s)

def solve_inner(moves, target):
    if target == 1:
        return 1
    visited = set()
    for i in itertools.count(start=2):
        visited |= moves 
        new_moves = set()
        for m in sorted(moves, key=lambda x: abs(target - x)):
            p = m + 1
            q = reverse(m)
            for c in sorted([p, q], reverse=True):
                if c not in visited:
                    new_moves.add(c)
                    if c == target:
                        return i
        moves = new_moves

def solve(n):
    return solve_inner(set([1]), n)

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
