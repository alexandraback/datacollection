#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline().strip().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    return readValues(str)

def turn(x, combo):
    for c in combo:
        x = x.replace("?", str(c), 1)
    return x

def solve(score0, score1):
    num0 = score0.count("?")
    num1 = score1.count("?")
    minDiff = None
    sol = None

    for combo0 in itertools.product(range(10), repeat=num0):
        for combo1 in itertools.product(range(10), repeat=num1):
            x0 = turn(score0, combo0)
            x1 = turn(score1, combo1)
           
            diff = abs(int(x0) - int(x1))
            if sol is None:
                minDiff = diff
                sol = x0, x1
            elif diff < minDiff:
                minDiff = diff
                sol = x0, x1

    return str(sol[0]) + " " + str(sol[1])

if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(*readInput()))
