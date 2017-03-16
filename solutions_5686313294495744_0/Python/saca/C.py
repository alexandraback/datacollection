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
    numTopics = readValue(int)
    topics = [readValues(str) for _ in range(numTopics)]
    return topics


def solve(topics):
    for numFakes in range(len(topics)):
        outerValid = False
        for fakes in itertools.combinations(range(len(topics)), numFakes):
            realFirsts = {topics[idx][0] for idx in range(len(topics)) if not idx in fakes}
            realSeconds = {topics[idx][1] for idx in range(len(topics)) if not idx in fakes}
            valid = True
            for fake in fakes:
                if not topics[fake][0] in realFirsts or not topics[fake][1] in realSeconds:
                    valid = False
                    break
            if valid:
                outerValid = True
        if not outerValid:
            return numFakes - 1


if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(readInput()))
