#!/usr/bin/python3
import sys
# import math
import fractions
from functools import lru_cache
sys.setrecursionlimit(1000000)
DEBUG = 0


def rl(convert='', a=False):
    line = sys.stdin.readline().split()
    for i, c in enumerate(convert):
        if c == 'i':
            line[i] = int(line[i])
        elif c == 's':
            pass
        elif c == 'f':
            line[i] = float(line[i])
    if not a and len(line) == 1:
        return line[0]
    return line


def gcd(*args):
    if len(args) == 0:
        return 0
    g = args[0]
    for i in range(1, len(args)):
        g = fractions.gcd(g, args[i])
    return g


def lcm(*args):
    if len(args) == 0:
        return 0
    g = args[0]
    for i in range(1, len(args)):
        g *= args[i]
    return g / gcd(*args)


def avg(a):
    return sum(a) / len(a)


def debug(*args, **kwargs):
    level = 1
    if 'level' in kwargs:
        level = kwargs.pop('level')
    if DEBUG >= level:
        print(*args, **kwargs)
        # pass


def o(i, x):
    print('Case #{}: {}'.format(i + 1, x))
# --------------------------------------------------------------------#


@lru_cache(maxsize=None)
def max_path_cnt(b):
    return 1 + (b - 1) * (b - 2)


def set_matrix(v, m, matrix, start_b, end_b):
    if m > 0:
        matrix[v][end_b - 1] = 1
        m -= 1
    for i in range(start_b, end_b):
        if m <= 0:
            break
        matrix[v][i] = 1
        m = set_matrix(i, m, matrix, start_b + 1, end_b)
    return m


tc = rl('i')

for t in range(tc):
    b, m = rl('ii')
    if max_path_cnt(b) < m:
        o(t, 'IMPOSSIBLE')
        debug(max_path_cnt(b))
    else:
        o(t, 'POSSIBLE')
        matrix = [[0] * b for _ in range(b)]
        set_matrix(0, m, matrix, 0, b)
        for line in matrix:
            print(''.join(str(x) for x in line))
