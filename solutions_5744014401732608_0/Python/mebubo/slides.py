from sys import stdin
from math import log, floor, ceil
import numpy as N

def decompose(n):
    result = []
    while True:
        result.append((n % 2))
        n = int(n / 2)
        if n == 0:
            break
    return result

def solve(case):
    B, M = case
    max_ = 2 ** (B-2)
    if max_ < M:
        return 'IMPOSSIBLE', []
    nInter = int(ceil(log(M, 2))) - 1
    rest = M - 2**nInter
    result = N.zeros((B, B), dtype=int)
    for j in range(1, nInter + 2):
        result[0, j] = 1
    result[0, B-1] = 1
    # print nInter, rest - 1

    for k in range(nInter):
        for j in range(k):
            result[k+1, j+1] = 1
        result[k+1, B-1] = 1

    for j, v in enumerate(decompose(rest-1)):
        result[nInter + 1, j+1] = v
        result[nInter + 1, B-1] = 1
    return 'POSSIBLE', result

def solveAll(cases):
    printAll(map(solve, cases))

def printMatrix(ls):
    for l in ls:
        print "".join(map(str, l))

def printAll(lines):
    for i, l in enumerate(lines):
        print "Case #%d: %s" % (i+1, l[0])
        printMatrix(l[1])

def main():
    T = int(stdin.readline())
    cases = []
    for t in range(T):
        bffs = map(int, stdin.readline().split())
        cases.append(bffs)
    solveAll(cases)

main()
