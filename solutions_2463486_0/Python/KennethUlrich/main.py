import argparse
import collections
import fractions
import functools
import itertools
import math
import operator

from sys import stdin
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

def solve(a, b):
    result = 0
    sqr_b = math.ceil(math.sqrt(b))
    max_prefix = int(str(sqr_b)[:1+math.floor(len(str(sqr_b)) / 2)])
    for i in range(1, max_prefix + 1):
        str_i = str(i)
        for candidate in (int(str_i + str_i[-2::-1]), int(str_i + str_i[::-1])):
            candidate_squared = candidate**2
            if a <= candidate_squared <= b:
                candidate_squared_str = str(candidate_squared)
                if candidate_squared_str == candidate_squared_str[::-1]:
                    result += 1
    return result

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