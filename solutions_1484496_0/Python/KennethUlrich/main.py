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
    n, *xs = read_ints()
    return [n, xs]

def solve(n, xs):
    #xs.sort()
    ret = [""]
    sums = {}
    for m in range(1, n + 1):
        for comb in itertools.combinations(xs, m):
            total = sum(comb)
            if total not in sums:
                sums[total] = comb
            else:
                return "\n{}\n{}".format(" ".join(str(v) for v in sums[total]), " ".join(str(v) for v in comb))
    return "Impossible"

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))