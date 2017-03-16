#!/usr/bin/python3
import sys
# import math
import fractions
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
    c, d, v = rl('iii')
    coins = rl('i' * d, a=True)
    vals = [True] + [False] * v
    for coin in coins:
        for i in reversed(range(0, v + 1)):
            if (i + coin) <= v:
                if vals[i]:
                    vals[i + coin] = True

    debug(vals)
    r = 0
    for coin in range(v + 1):
        if not vals[coin]:
            debug('adding', coin)
            for i in reversed(range(v + 1)):
                if (i + coin) <= v:
                    if vals[i]:
                        vals[i + coin] = True
            vals[coin] = True
            r += 1
            debug(vals)
    o(t, r)
