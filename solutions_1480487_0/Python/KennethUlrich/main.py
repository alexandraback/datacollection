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
    ret = []
    total_pts = sum(xs)
    avg_pts = total_pts / n
    goal = avg_pts * 2
    unsafe = [x for x in xs if x < 2 * avg_pts]
    for x in xs:
        if x not in unsafe:
            ret.append(str(0.0))
        else:
            val = max(0, 100 * ((sum(unsafe) / len(unsafe)) + (total_pts / len(unsafe)) - x) / total_pts)
            ret.append(str(val))
    return " ".join(ret)

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))