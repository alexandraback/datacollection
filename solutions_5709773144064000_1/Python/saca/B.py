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


def computeTime(numFactories):
    global C, F, X
    if numFactories == 0:
        return X / 2
    time = 0
    for i in range(numFactories):
        time += C / (2 + i * F)
    return time + X / (2 + numFactories * F)


def funcSlowSolve():
    numFactories = 0
    while computeTime(numFactories) > computeTime(numFactories + 1):
        numFactories += 1

    return computeTime(numFactories)


def funcFastSolve():
    global C, F, X

    left = 0
    right = X / 2

    while True:
        mid = (left + right) // 2
        time0 = computeTime(mid)
        time1 = computeTime(mid + 1)
        if time0 <= time1:
            return time0
        else:
            pass


def bruteSolve():
    global C, F, X
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
    Mouth.answer(solve())
