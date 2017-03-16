import fractions
import functools
import itertools
import math
import operator

from sys import stdin
from multiprocessing import Pool

def solve_star(args):
    return solve(*args)

def read_floats():
    return [float(n) for n in stdin.readline().strip().split()]

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return [int(n) for n in stdin.readline().strip().split()]

def read_words():
    return stdin.readline().strip()

def parse():
    a, b = read_ints()
    f = read_floats()
    return [a, b, f]

def solve(a, b, f):
    v = []
    z = 1.0
    p = f[0]
    chars_left = b + (a - 1)
    cost = p * (chars_left) + (1.0 - p) * (chars_left + b + 1)
    v.append(cost)
    for i in range(1, a):
        chars_left -= 2
        p = p * (f[i])
        cost = p * (chars_left) + (1.0 - p) * (chars_left + b + 1)
        v.append(cost)
    best = float(2 + b)
    for val in v:
        if val < best:
            best = val 
    return best

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))