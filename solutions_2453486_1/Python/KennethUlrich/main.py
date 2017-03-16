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
    v = []
    for j in range(4):
        v.append([c for c in read_words()])
    read_words()
    return [v]

def solve(v):    
    def winner(v):
        for player in "X", "O":
            if all(c in (player, "T") for c in v):
                return " ".join([player, "won"])
    for a in itertools.chain(v, zip(*v), [[v[i][i] for i in range(4)]], [[v[i][3-i] for i in range(4)]]):
        w = winner(a)
        if w:
            return w
    if "." not in itertools.chain.from_iterable(v):
        return "Draw"
    else:
        return "Game has not completed"

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