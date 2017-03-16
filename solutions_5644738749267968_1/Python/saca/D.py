#!/usr/bin/env python3


import sys


def readFloats():
    return list(map(float, sys.stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}: {} {}".format(cls.count, answer[1], answer[0]))
        cls.count += 1


def solveWar():
    global Naomi, Ken
    Naomi.sort()
    Ken.sort()

    won = 0
    kenIdx = 0
    for N in Naomi:
        while kenIdx < len(Ken) and Ken[kenIdx] < N:
            kenIdx += 1
        if kenIdx == len(Ken):
            won += 1
        else:
            kenIdx += 1

    return won


def solveDeceitfulWar():
    global Naomi, Ken
    Naomi.sort()
    Ken.sort(reverse=True)
    won = 0
    nMaxIdx = len(Naomi) - 1

    for ken in Ken:
        if ken < Naomi[nMaxIdx]:
            won += 1
            nMaxIdx -= 1

    return won


def solve():
    return solveWar(), solveDeceitfulWar()


for _ in range(int(sys.stdin.readline())):
    sys.stdin.readline()
    Naomi = readFloats()
    Ken = readFloats()
    Mouth.answer(solve())
