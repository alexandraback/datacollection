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
    return readValues(int)

matr = []
vis = []

def numWays(B, M, node=0):
    global matr
    global vis

    if node == B - 1:
        return 1

    vis[node] = True
    total = 0

    for idx, slide in enumerate(matr[node]):
        if slide == "1":
            if vis[idx]:
                return -1
            else:
                ways = numWays(B, M, idx)
                if ways == -1:
                    return -1
                else:
                    total += ways
    vis[node] = False
    return total
    

def recurse(B, M, numRow):
    global matr
    global vis

    if numRow == B - 1:
        vis = [False] * B
        return numWays(B, M) == M

    for row in itertools.product("01", repeat=B):
        if row[numRow] == "1":
            continue
        ok = True
        for idx in range(numRow):
            if row[idx] == "1" and matr[idx][numRow] == "1":
                ok = False
                break
        if not ok:
            continue

        matr[numRow] = row
        if recurse(B, M, numRow + 1):
            return True
    return False

def solve(B, M):
    global matr
    matr = [["0"] * B] * B

    ans = recurse(B, M, 0)
    if ans:
        return "POSSIBLE\n" + "\n".join("".join(row) for row in matr)
    else:
        return "IMPOSSIBLE"

if __name__ == '__main__':
    for _ in range(readValue(int)):
        Mouth.answer(solve(*readInput()))
