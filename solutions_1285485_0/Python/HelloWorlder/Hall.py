#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20


def close(s, x, D):
    return (s[0] - x[0]) ** 2 + (s[1] - x[1]) ** 2 <= D ** 2

def inCorner(pos, corner):
    return (pos[0] - corner[0]) * corner[2] > 0 and (pos[1] - corner[1]) * corner[3] > 0

def getStatueSet(x, mirrors, corners, D):
    statueList = list([x])
    statueSet = set()
    while statueList:
        pos = statueList.pop()
        statueSet.add(pos)
        for mirror in mirrors:
            if mirror[0] is not None and (pos[0] - mirror[0]) * mirror[4] > 0:
                sx = mirror[0] * 2 - pos[0]
                sy = pos[1]
            elif mirror[1] is not None and (pos[1] - mirror[1]) * mirror[4] > 0:
                sx = pos[0]
                sy = mirror[1] * 2 - pos[1]
            statue = (sx, sy)
            if statue not in statueSet and close(statue, x, D):
                statueList.append(statue)

        for corner in corners:
            if inCorner(pos, corner):
                sx = corner[0] * 2 - pos[0]
                sy = corner[1] * 2 - pos[1]
                statue = (sx, sy)
                if statue not in statueSet and close(statue, x, D):
                    statueList.append(statue)
    return statueSet

def sameLineSide(x, s, statue):
    X21 = s[0] - x[0]
    Y21 = s[1] - x[1]
    X31 = statue[0] - x[0]
    Y31 = statue[1] - x[1]
    sameLine = (X21 * Y31 == X31 * Y21)
    sameSide = (X21 * X31 >= 0 and Y21 * Y31 >= 0)
    return sameLine and sameSide

def removeStatueFor(s, x, statueSet):
    toRemoveSet = set()
    for statue in statueSet:
        if sameLineSide(x, s, statue):
            toRemoveSet.add(statue)
    statueSet.difference_update(toRemoveSet)

def solve(H, W, D, X, hall):
    h = H - 2
    w = W - 2
    mirrors = [(0, None, 0, w - 2, 1), (None, 0, 0, h, 1), (h, None, 0, w, -1), (None, w, 0, h, -1)]
    mirrorsBlocks = \
        set([(0, y) for y in range(W)]) | \
        set([(x, 0) for x in range(H)]) | \
        set([(H, y) for y in range(W)]) | \
        set([(x, W) for x in range(H)])
    corners = [(0, 0, 1, 1), (0, w, 1, -1), (h, 0, -1, 1), (h, w, -1, -1)]
    x = (X[0] - 0.5, X[1] - 0.5)
    statueSet = getStatueSet(x, mirrors, corners, D)
    statueSet.discard(x)
    
    result = 0
    while statueSet:
        result += 1
        statue = statueSet.pop()
        removeStatueFor(statue, x, statueSet)
    return result

if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit();

    inFile = open(sys.argv[1])
    outFile = open(sys.argv[2], "w")

    startTime = datetime.datetime.now()
    print "Start Time = %s" % startTime
    print SEPARATE_LINE

    T = int(inFile.readline())
    for i in range(T):
        HWD = inFile.readline().strip().split()
        H = int(HWD[0])
        W = int(HWD[1])
        D = int(HWD[2])
        hall = dict()
        for x in range(H):
            line = inFile.readline().strip()
            for y in range(W):
                ch = line[y]
                hall[(x, y)] = ch
                if ch == "X":
                    X = (x, y)
        small = True
        if small:
            result = solve(H, W, D, X, hall)
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
