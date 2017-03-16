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
    global J, P, S, K
    J, P, S, K = tuple(readValues(int))

sol = []

def isValid(pick, K):
    for combo in itertools.combinations(range(3), 2):
        counts = collections.defaultdict(int)
        for comb in ((p[combo[0]], p[combo[1]]) for p in pick):
            counts[comb] += 1
            if counts[comb] > K:
                return False
    return True

def brute():
    global J, P, S, K, sol
    
    ways = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                ways.append((j, p, s))

    for picks in range(1, len(ways) + 1):
        valid = False
        for pick in itertools.combinations(ways, picks):
            if isValid(pick, K):
                valid = True
                sol = pick
                break
        if not valid:
            return sol
    return sol

def solve():
    global sol

    brute()
    return str(len(sol)) + "\n" + "\n".join(" ".join(str(x + 1) for x in pick) for pick in sol)

if __name__ == '__main__':
    for _ in range(readValue(int)):
        readInput()
        Mouth.answer(solve())
