#!/usr/bin/env python3
import math, collections, itertools
from sys import stdin


def readValue(valueType):
    return valueType(stdin.readline())


def readValues(valueType):
    return list(map(valueType, stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {}".format(cls.count, answer))
        cls.count += 1


def readInput():
    return readValue(str).strip()


numbers = [
    "ZERO",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE"
]


def recurse(left, last):
    if not left:
        return ''
    for idx in range(last, len(numbers)):
        tmp = left
        matches = True
        for letter in numbers[idx]:
            pos = tmp.find(letter)
            if pos == -1:
                matches = False
                break
            tmp = tmp[:pos] + tmp[pos+1:]
        if matches:
            further = recurse(tmp, last)
            if further is not None:
                return str(idx) + further
    return None

def solve(coded):
    return recurse(coded, 0)

if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(readInput()))
