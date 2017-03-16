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
    n, _ = read_ints()
    for i in range(n):
        v.append([[i, 100] for i in read_ints()])
    return [v]

def solve(v):
    for i in range(2):
        for row in v:
            height = max(t[0] for t in row)
            for grass in row:
                grass[1] = min(grass[1], height)
        v = list(zip(*v))
    return "YES" if all(t[0] == t[1] for t in itertools.chain.from_iterable(v)) else "NO"

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