#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline().split('/')))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    return readValues(int)


_MAX_LVL = 40
_CACHE = {}


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def rec(a, b, lvl=0):
    global _MAX_LVL, _CACHE
    #print(a, b, lvl)

    if lvl == _MAX_LVL:
        return _MAX_LVL
    if a == b:
        return lvl
    if a in _CACHE:
        return _CACHE[a]

    bestAncestor = _MAX_LVL
    for p in range(max(0, a * 2 - b), (a * 2) // 2):
        if p == 0:
            bestAncestor = min(rec(a * 2 - p, b, lvl + 1), bestAncestor)
        else:
            left = rec(p, b, lvl + 1)
            if left == _MAX_LVL:
                continue
            right = rec(a * 2 - p, b, lvl + 1)
            if right == _MAX_LVL:
                continue
            bestAncestor = min(rec(p, b, lvl + 1), rec(a * 2 - p, b, lvl + 1), bestAncestor)
        if bestAncestor == lvl + 1:
            break

    #print(a, b, '->', bestAncestor)
    _CACHE[a] = bestAncestor
    return bestAncestor


def solve(*args, **kwargs):
    global _CACHE, _MAX_LVL
    p, q = args[0]
    g = gcd(p, q)
    p //= g
    q //= g

    _CACHE = {}
    ret = rec(p, q)
    if ret == _MAX_LVL:
        return 'impossible'
    return ret


if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(readInput()))
