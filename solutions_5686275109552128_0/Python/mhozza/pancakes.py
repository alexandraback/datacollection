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
# --------------------------------------------------------------------#


def o(i, x):
    print('Case #{}: {}'.format(i + 1, x))


def split(p, k):
    pp = p[:]
    pp[0] = p[0] - k
    pp.append(k)
    return pp


def solve(p):
    p = sorted(p, reverse=True)
    if p[0] > 3:
        return min(p[0], 1 + min(solve(split(p, k)) for k in range(2, 1 + p[0] // 2)))
    else:
        return p[0]


tc = rl('i')

for t in range(tc):
    d = rl('i')
    p = rl('i' * d, True)
    o(t, solve(p))
