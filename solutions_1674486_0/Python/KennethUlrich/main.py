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
    dict = {}
    n = read_int()
    for i in range(1, n + 1):
        num, *supers = read_ints()
        dict[i] = [s for s in supers]
    return [dict]

def p(dict, k):
    ret = [k]
    for v in dict[k]:
        ret.extend(p(dict, v))
    return ret
            
def solve(dict):
    for k in dict.keys():
        parents = p(dict, k)
        if len(parents) > len(set(parents)):
            return "Yes"
    return "No"

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))