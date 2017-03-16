#!/usr/bin/env python

import sys


def solve(B, M):
    if M > 2 ** (B - 2):
        return None
    result = [[0] * B for _ in xrange(B)]
    for i in xrange(1, B):
        for j in xrange(i, B):
            if (i != j):
                result[i][j] = 1
    #print matrix2str(result)
    d = 2 ** (B - 2)
    k = 0
    while M:
        if d > 1:
            d = d / 2
        k+= 1
        if M >= d:
            result[0][k] = 1
            M-= d
    return result


def matrix2str(matrix):
    return "\n".join("".join(map(str, row)) for row in matrix)


if __name__ == '__main__':
    sys.stdin.readline()
    casenum = 0
    for line in sys.stdin:
        casenum+= 1
        B, M = map(int, line.split())
        answer = solve(B, M)
        print "Case #%s:" % casenum, ('POSSIBLE' if answer else 'IMPOSSIBLE')
        if answer:
            print matrix2str(answer)
