import os
import random


def countWays(matrix, visited, x):
    s = 0
    for x1 in range(b):
        if x1 != x and matrix[x][x1] == 1:
            if visited[x1]:
                return None
            if x1 == b - 1:
                s += 1
            else:
                visited1 = visited[:]
                visited1[x1] = True
                w = countWays(matrix, visited1, x1)
                if w is None:
                    return None
                s += w
    return s

def test1(matrix):
    b = len(matrix)    
    visited = [False for x in range(b)]
    visited[0] = True
    
    m2 = countWays(matrix, visited, 0)
    print "matrix, countWays", matrix, m2

def test():
    b = 5
    g = 0
    wMax = 0
    for i in range(2 ** 20):
        # matrix = [[1 if y < b - 1 and x != y and hasBit(i, y * 5 + x - (y if x < y else y + 1)) \
        #         else 0 for x in range(b)] for y in range(b)]
        matrix = [[1 if y != b - 1 and hasBit(i, y * 5 + x) else 0 for x in range(b)] for y in range(b)]
        if i == 0:
            matrix = [[1 if x > y else 0 for x in range(b)] for y in range(b)]
        matrix[b - 1] = [0 for x in range(b)]
        for x in range(b):
            matrix[x][x] = 0
        visited = [False for x in range(b)]
        visited[0] = True
        # w = countWays(matrix, visited, 0)
        
        visited = [False for x in range(b)]
        visited[0] = True
        
        m2 = countWays(matrix, visited, 0)
        
        test1(matrix)
        if m2 is not None:
            g += 1
            wMax = max(m2, wMax)
            # print w
        if m2 is not None and m2 > 16:
            print m2, matrix
            assert(False)
        if i % 1000 == 1:
            print i, wMax
            return
            
        
    print "g, wMax", g, wMax
            


def countPaths(matrix, x, b):
    if x == b - 1:
        return 1
    r = 0
    
    for i in range(x + 1, b):
        if matrix[x][i] == 1:
            r += countPaths(matrix, i, b)
    return r
  

def hasBit(n, pos):
    return (n & (1 << pos)) != 0

def getResultMultiLine(b, m):
    mFirst = m
    mMax = 2 ** (b - 2)
    if m > mMax:
        return None
    matrix = [[0 for i in range(b)] for j in range(b)]
    if m == mMax:
        matrix[0][b - 1] = 1
        m -= 1
    for i in range(1, b - 1):
        if hasBit(m, b - i - 2):
            matrix[0][i] = 1
    for y in range(1, b - 1):
        for x in range(y + 1, b):
            matrix[y][x] = 1
    m1 = countPaths(matrix, 0, b)
    visited = [False for x in range(b)]
    visited[0] = True
    m2 = countWays(matrix, visited, 0)
    test1(matrix)
    test1(matrix)
    print m1, m2, mFirst
    if m1 != mFirst or m2 != m1:
        print "Incorrect", m1, m2, mFirst
        assert(False)
    print matrix, m2
    return [" ".join(map(str, matrixLine)) for matrixLine in matrix]


if __name__ == "__main__":
    test()
    folder = "D:\\Programming\\Java\\CodeJam3\\src\\shutovich\\"
    nameParts = ["B-test", "B-small-attempt1", "B-large"]
    namePart = None
    for namePart1 in nameParts:
        if os.path.exists(folder + namePart1 + ".in"):
            namePart = namePart1
            print "Using " + namePart
    lines = [s[:len(s) - 1] for s in open(folder + namePart + ".in", "r")]
    count = int(lines[0])
    resultLines = []
    iLine = 1
    
    multiLineResult = True
    
    for iTry in range(count):
        iLastResult = len(resultLines)
        (b, m) = map(int, lines[iLine].split())
        if multiLineResult:
            result = getResultMultiLine(b, m)
            resultLines.append("Case #" + str(iTry + 1) + ": " + ("POSSIBLE" if result is not None else "IMPOSSIBLE"))
            if result is not None:
                resultLines += result
        else:
            resultLines.append("Case #" + str(iTry + 1) + ": " + getResult())
        for j in range(iLastResult, len(resultLines)):
            print resultLines[j]
        iLine += 1
    with open(folder + namePart + ".out", "wt") as oFile:
        for resultLine in resultLines:
            oFile.write(resultLine + "\n")
            