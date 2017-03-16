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


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def rec(a, b, lvl=0):
    global _MAX_LVL, _CACHE

    g = gcd(a, b)
    a //= g
    b //= g
    if b & (b-1):
        return _MAX_LVL
    idx = (a - 1) // 2 + 1
    pw2 = math.log(b) / math.log(2)
    return int(pw2 - math.log(idx) / math.log(2))


def solve(*args, **kwargs):
    global _MAX_LVL
    p, q = args[0]
    g = gcd(p, q)
    p //= g
    q //= g

    ret = rec(p, q)
    if ret == _MAX_LVL:
        return 'impossible'
    return ret


if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(readInput()))
