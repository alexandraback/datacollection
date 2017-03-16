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
    v = []
    for i in range(read_int()):
        a, b = read_ints()
        v.append((i, a, b))
    return [v]

def solve(v):
    s1, s2 = collections.defaultdict(set), collections.defaultdict(set)
    for i, a, b in v:
        s1[a].add(i)
        s2[b].add(i)
    #print(s1, s2)
    #print("***")
    s = 0
    left = len(v)
    ret = 0
    used1, used2 = set(), set()
    while left:

        ok = False
        ret += 1
        for i in reversed(range(s + 1)):
            for z in s2[i]:
                if z not in used2:
                    used2.add(z)
                    s += 1                 
                    if z not in used1:
                        used1.add(z)
                        s += 1
                    left -= 1
                    #print()
                    ok = True
                    break
            if ok:
                break
        if not ok:
            for i in reversed(range(s + 1)):
                for z in s1[i]:
                    if z not in used1:
                        used1.add(z)
                        s += 1
                        ok = True
                        break
                if ok:
                    break
        if not ok:
            return "Too Bad"
    return ret

if __name__ == '__main__':
    pool = Pool()
    iter = pool.imap(solve_star, (parse() for i in range(read_int())))
    for i, result in enumerate(iter):
        print("Case #{}: {}".format(i + 1, result))