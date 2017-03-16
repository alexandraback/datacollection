#!/usr/bin/env python3


import sys


def readInt():
    return int(sys.stdin.readline())


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {:0.7f}".format(cls.count, answer))
        cls.count += 1


def bruteSolve(C, F, X):
    prod = 2
    time = 0

    while True:
        timeToX = X / prod

        timeToC = C / prod
        timeToNextX = timeToC + X / (prod + F)

        if timeToNextX < timeToX:
            time += timeToC
            prod += F
        else:
            break
    return time + X / prod


for _ in range(readInt()):
    C, F, X = map(float, sys.stdin.readline().split())

    solve = bruteSolve
    Mouth.answer(solve(C, F, X))
