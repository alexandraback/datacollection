#!/usr/bin/python3
import sys
# import math
import fractions
from functools import reduce
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
    print('Case #{}: {}'.format(i + 1, 'YES' if x else 'NO'))


def op(a, b):
    debug(a, b)
    if a < 0:
        return -op(-a, b)
    if b < 0:
        return -op(a, -b)

    if a == 1:
        return b
    if b == 1:
        return a
    if a == b:
        return -1
    if a == 2:
        if b == 3:
            return 4
        else:
            return -3
    if a == 3:
        if b == 2:
            return -4
        else:
            return 2
    if a == 4:
        if b == 2:
            return 3
        else:
            return -2


tc = rl('i')

for t in range(tc):
    l, x = rl('ii')
    s = rl('s')
    d = {
        'i': 2,
        'j': 3,
        'k': 4,
    }
    ls = list(map(lambda x: d[x], s))
    v = reduce(op, ls, 1)
    if (v == 1) or (v == -1 and x % 2 != 1) or (abs(v) > 1 and x % 4 != 2):
        debug('Kukuc')
        o(t, False)
    else:
        if v != -1:
            x /= 2
            ls = ls * 2
        if x >= 3:
            ls = ls * 3
        debug(ls)
        r = 1
        oki = False
        okj = False
        okk = False
        for c in ls:
            r = op(r, c)
            debug(r)
            if not oki and r == 2:
                oki = True
                r = 1
            if not okj and oki and r == 3:
                okj = True
                r = 1
            if not okk and okj and r == 4:
                okk = True
        o(t, okk)
