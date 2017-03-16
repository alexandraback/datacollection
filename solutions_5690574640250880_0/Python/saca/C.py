#!/usr/bin/env python3


import sys


def readInts():
    return list(map(int, sys.stdin.readline().split()))


class Mouth():
    count = 1

    @classmethod
    def answer(cls, answer):
        print("Case #{}:\n{}".format(cls.count, answer))
        cls.count += 1


def solveNo1():
    global R, C, M, vis, numFreeCellsLeft
    rowStacks = [0] * R
    cellNextToMine = [[False] * C for _ in range(R)]
    vis = [[False] * C for _ in range(R)]
    numFreeCellsLeft = R * C - M

    def numExpanded(row, col):
        vis[row][col] = True
        if col + 1 > rowStacks[row]:
            return 0
        if cellNextToMine[row][col]:
            return 1
        ans = 1
        for nextRow in (row, row + 1, row - 1):
            if nextRow < 0 or nextRow >= R:
                continue
            for nextCol in (col, col + 1, col - 1):
                if nextCol < 0 or nextCol >= C:
                    continue
                if not vis[nextRow][nextCol]:
                    ans += numExpanded(nextRow, nextCol)
        return ans

    def recurse(row):
        global vis, numFreeCellsLeft

        if row == R and numFreeCellsLeft:
            return False
        if numFreeCellsLeft == 0:
            # check valid
            for row in range(R):
                for col in range(rowStacks[row]):
                    nextToMine = False
                    # above
                    if row > 0 and min(col + 2, C) > rowStacks[row - 1]:
                        nextToMine = True
                    # right
                    if col < C - 1 and col + 1 == rowStacks[row]:
                        nextToMine = True
                    # below
                    if row < R - 1 and min(col + 2, C) > rowStacks[row + 1]:
                        nextToMine = True
                    cellNextToMine[row][col] = nextToMine
                    vis[row][col] = False

            #print('rowStacks: ' + str(rowStacks))
            #print('\n'.join(str(row) for row in cellNextToMine))
            return numExpanded(0, 0) == R * C - M

        for rowStack in range(min(numFreeCellsLeft, C), 0, -1):
            rowStacks[row] = rowStack
            numFreeCellsLeft -= rowStack
            if recurse(row + 1):
                return True
            rowStacks[row] = 0
            numFreeCellsLeft += rowStack
        return False
    
    def stacksToSolution(rowStacks):
        sol = ''
        for rowStack in rowStacks:
            sol += '.' * rowStack + '*' * (C - rowStack) + '\n'
        return 'c' + sol[1:-1]

    # set initial row stack and recurse
    if recurse(0):
        return stacksToSolution(rowStacks)
    return None


for _ in range(int(sys.stdin.readline())):
    #print('--------------------------')
    R, C, M = readInts()
    solve = solveNo1
    ans = solve()
    Mouth.answer(ans if ans is not None else 'Impossible')
