#!/usr/bin/env python
# -*- coding: utf-8 -*-

def nbpaths(matrix):
    B = len(matrix)
    weight = [0]*B
    weight[B-1] = 1
    for B1 in range(B-1, -1, -1):
        for B2 in range(B1+1, B):
            if matrix[B1][B2] == 1:
                weight[B1]+=weight[B2]

    return weight[0]

def diagonal(B):
    matrix = []
    for i in range(B):
        row = [0]*B
        if i != B-1:
            row[i+1] = 1
        matrix.append(row)
    return matrix

def printMatrix(matrix):
    for row in matrix:
        print "".join(map(str, row))

def nbPos(B):
    if B == 3:
        return 1
    if B == 4:
        return 3
    if B == 5:
        return 6
    if B == 6:
        return 10
def matrixPos(pos, B):
    if B == 3:
        if pos == 0:
            return 0, 2
    if B == 4:
        if pos == 0:
            return 0, 2
        if pos == 1:
            return 0, 3
        if pos == 2:
            return 1, 3
    if B == 5:
        if pos == 0:
            return 0, 2
        if pos == 1:
            return 0, 3
        if pos == 2:
            return 0, 4
        if pos == 3:
            return 1, 3
        if pos == 4:
            return 1, 4
        if pos == 5:
            return 2, 4
    if B == 6:
        if pos == 0:
            return 0, 2
        if pos == 1:
            return 0, 3
        if pos == 2:
            return 0, 4
        if pos == 3:
            return 0, 5
        if pos == 4:
            return 1, 3
        if pos == 5:
            return 1, 4
        if pos == 6:
            return 1, 5
        if pos == 7:
            return 2, 4
        if pos == 8:
            return 2, 5
        if pos == 9:
            return 3, 5

if __name__ == "__main__":
    testcases = int(raw_input())
    for caseNr in xrange(1, testcases+1):
        B, M = map(int, raw_input().split(" "))
        if M > 2**(B-2):
            print("Case #%i: %s" % (caseNr, "IMPOSSIBLE"))
        else:
            solution = ""
            startMatrix = diagonal(B)
            if M == 1:
                print("Case #%i: %s" % (caseNr, "POSSIBLE"))
                printMatrix(startMatrix)
            else:
                for i in range(2**nbPos(B)):
                    for j in range(nbPos(B)):
                        r, c = matrixPos(j, B)
                        startMatrix[r][c] = 1 if (i & (1<<j) > 0) else 0
                    if nbpaths(startMatrix) == M:
                        print("Case #%i: %s" % (caseNr, "POSSIBLE"))
                        printMatrix(startMatrix)
                        break
                else:
                    print("Case #%i: %s" % (caseNr, "IMPOSSIBLE"))