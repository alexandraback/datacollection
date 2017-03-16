#!/usr/bin/env python

from __future__ import print_function
from itertools import *

def mkMineMap(R, C, pattern):
    shorter, longer = min(R, C), max(R, C)
    mineMap = ['c' + '.' * (pattern[0] - 1) + '*' * (longer - pattern[0])]
    for p in pattern[1:]:
        mineMap.append('.' * p + '*' * (longer - p))
    mineMap.extend(['*' * longer] * (shorter - len(mineMap)))
    if C < R:
        mineMap = map(''.join, map(None, *mineMap)) # transpose
    return mineMap

def solveCase(R, C, M):
    shorter, longer = min(R, C), max(R, C)
    neededVoids = R*C - M
    if shorter == 1 or neededVoids == 1:
        return mkMineMap(R, C, [neededVoids])
    elif neededVoids in (2, 3, 5, 7):
        return
    elif shorter == 2:
        if neededVoids % 2 == 0: return mkMineMap(R, C, [neededVoids/2] * 2)
        else: return
    else:
        p = [longer] * (neededVoids / longer - 2)
        neededVoids -= longer * len(p)
        evilSpecialCase = len(p) == 1 and neededVoids == longer*2 + 1
        if neededVoids % 2 == 1:
            neededVoids -= 3
            plusThree = 3 
        else: plusThree = 0
        if neededVoids > longer*2:
            p.extend([longer, longer, neededVoids - longer*2 + plusThree])
        else:
            p.extend([neededVoids / 2, neededVoids / 2])
            if plusThree:
                p.append(3)
        if evilSpecialCase:
            p[1] += 1
            p[-1] -= 1
        return mkMineMap(R, C, p)

# Testing
def neighbors(point, map):
    result = []
    shifts = [(y, x) for y in (-1, 0, 1) for x in (-1, 0, 1)]
    shifts.remove((0,0))
    for s in shifts:
        newPoint = (point[0] + s[0], point[1] + s[1])
        if (newPoint[0] >= 0 and newPoint[0] < len(map) and
            newPoint[1] >= 0 and newPoint[1] < len(map[0])):
            result.append(newPoint)
    return result

def neighborMines(point, map):
    mines = 0
    for n in neighbors(point, map):
        if map[n[0]][n[1]] == '*':
            mines += 1
    return mines

def checkMap(m):
    assert m[0][0] == 'c'
    assert len(set(map(len, m))) == 1
    uncovered = {(0, 0)}
    queue = [(0,0)]
    while queue:
        point = queue.pop()
        if neighborMines(point, m) == 0:
            for p2 in neighbors(point, m):
                if p2 not in uncovered:
                    queue.append(p2)
                    uncovered.add(p2)
    numMines = sum(r.count('*') for r in m)
    assert len(uncovered) == len(m) * len(m[0]) - numMines

def main():
    T = int(raw_input())
    for t in xrange(1, T+1):
        R, C, M = map(int, raw_input().split())
        mineMap = solveCase(R, C, M)
        print('Case #{}:'.format(t))
        if mineMap: 
            map(print, mineMap)
        else: print('Impossible')

if __name__ == "__main__":
    main()

