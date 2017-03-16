__author__ = 'Servy'

import sys
import itertools


def findAWay(path, order, flights):
    if len(order) == 0:
        return True

    nextHop = order.pop(0)

    while True:
        if len(path) == 0:
            return False

        currentHop = path.pop()
        if flights[currentHop][nextHop]:
            path.append(currentHop)
            path.append(nextHop)
            if findAWay(path[:], order[:], flights):
                return True
            path.pop()
            path.pop()


def calcScore(order, flights, zips):
    originalOrder = order[:]
    path = [order.pop(0)]
    if findAWay(path, order, flights):
        return int("".join(map(lambda x: zips[x-1], originalOrder)))
    else:
        return 1000000 ** n


testNumber = int(sys.stdin.readline().strip())
for test in range(1, testNumber + 1):
    (n, m) = map(int, sys.stdin.readline().split())
    zips = []
    for i in range(n):
        zips.append(sys.stdin.readline().strip())

    flights = [[False for i in range(n+1)] for j in range(n+1)]
    for i in range(m):
        a, b = map(int, sys.stdin.readline().split())
        flights[a][b] = True
        flights[b][a] = True

    bestScore = 1000000 ** n
    for permutation in itertools.permutations(range(1, n+1)):
        score = calcScore(list(permutation), flights, zips)
        if score < bestScore:
            bestScore = score

    print("Case #%d: %d" % (test, bestScore))