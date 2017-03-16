#!/usr/bin/python3
import sys
# import math
import fractions
from collections import defaultdict

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

tc = rl('i')

for t in range(tc):
    j, p, s, k = rl('iiii')
    couplesAB = defaultdict(int)
    couplesBC = defaultdict(int)
    couplesAC = defaultdict(int)
    out = list()
    cnt = 0
    for a in range(j):
        for b in range(p):
            for c in range(s):
                if couplesAB[(a, b)] < k and couplesAC[(a, c)] < k and couplesBC[(b, c)] < k:
                    couplesAB[(a, b)] += 1
                    couplesAC[(a, c)] += 1
                    couplesBC[(b, c)] += 1
                    out.append((a + 1, b + 1, c + 1))
                    cnt += 1
    o(t, cnt)
    for l in out:
        print(*l)
