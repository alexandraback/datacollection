#!/usr/bin/python

import sys, datetime

SEPARATE_LINE = "=" * 20

def topleftCorner(x, y, hall):
    return \
        hall.get((x - 1, y - 1)) == "#" and \
        hall.get((x - 1, y)) == "#" and \
        hall.get((x, y - 1)) == "#"

def toprightCorner(x, y, hall):
    return \
        hall.get((x - 1, y + 1)) == "#" and \
        hall.get((x - 1, y)) == "#" and \
        hall.get((x, y + 1)) == "#"

def downleftCorner(x, y, hall):
    return \
        hall.get((x + 1, y - 1)) == "#" and \
        hall.get((x + 1, y)) == "#" and \
        hall.get((x, y - 1)) == "#"

def downrightCorner(x, y, hall):
    return \
        hall.get((x + 1, y + 1)) == "#" and \
        hall.get((x + 1, y)) == "#" and \
        hall.get((x, y + 1)) == "#"

def getCorners(H, W, D, X, hall):
    corners = list()
    for x in range(H):
        for y in range(W):
            if hall.get((x, y)) == "X" or hall.get((x, y)) == ".":
                if topleftCorner(x, y, hall):
                    # corner ((x, y), (dirx, diry))
                    corner = ((x - 0.5, y - 0.5) , (1, 1))
                    if isClose(D, X, corner[0]):
                        corners.append(corner)
                if toprightCorner(x, y, hall):
                    corner = ((x - 0.5, y + 0.5), (1, -1))
                    if isClose(D, X, corner[0]):
                        corners.append(corner)
                if downleftCorner(x, y, hall):
                    corner = ((x + 0.5, y - 0.5), (-1, 1))
                    if isClose(D, X, corner[0]):
                        corners.append(corner)
                if downrightCorner(x, y, hall):
                    corner = ((x + 0.5, y + 0.5), (-1, -1))
                    if isClose(D, X, corner[0]):
                        corners.append(corner)
    return corners

def topleftBlind(x, y, hall):
    top = hall.get((x - 1, y))
    left = hall.get((x, y - 1))
    topleft = hall.get((x - 1, y - 1))
    return \
        (top == "X" or top == ".") and \
        (left == "X" or left == ".") and \
        (topleft == "X" or topleft == ".")

def toprightBlind(x, y, hall):
    top = hall.get((x - 1, y))
    right = hall.get((x, y + 1))
    topright = hall.get((x - 1, y + 1))
    return \
        (top == "X" or top == ".") and \
        (right == "X" or right == ".") and \
        (topright == "X" or topright == ".")

def downleftBlind(x, y, hall):
    down = hall.get((x + 1, y))
    left = hall.get((x, y - 1))
    downleft = hall.get((x + 1, y - 1))
    return \
        (down == "X" or down == ".") and \
        (left == "X" or left == ".") and \
        (downleft == "X" or downleft == ".")

def downrightBlind(x, y, hall):
    down = hall.get((x + 1, y))
    right = hall.get((x, y + 1))
    downright = hall.get((x + 1, y + 1))
    return \
        (down == "X" or down == ".") and \
        (right == "X" or right == ".") and \
        (downright == "X" or downright == ".")

def getBlindPoints(H, W, X, hall):
    blindPoints = list()
    for x in range(H):
        for y in range(W):
            if hall.get((x, y)) == "#":
                if x < X[0] and y < X[1]:
                    if topleftBlind(x, y, hall):
                        blindPoints.append((x, y))
                elif x < X[0] and y > X[1]:
                    if toprightBlind(x, y, hall):
                        blindPoints.append((x, y))
                elif x > X[0] and y < X[1]:
                    if downleftBlind(x, y, hall):
                        blindPoints.append((x, y))
                elif x > X[0] and y > X[1]:
                    if downrightBlind(x, y, hall):
                        blindPoints.append((x, y))
    return blindPoints

def topMirror(x, y, hall):
    return hall.get((x - 1, y)) == "#"

def downMirror(x, y, hall):
    return hall.get((x + 1, y)) == "#"

def leftMirror(x, y, hall):
    return hall.get((x, y - 1)) == "#"

def rightMirror(x, y, hall):
    return hall.get((x, y + 1)) == "#"

def getMirrors(H, W, hall):
    mirrors = list()
    for x in range(H):
        for y in range(W):
            if hall.get((x, y)) == "X" or hall.get((x, y)) == ".":
                if topMirror(x, y, hall):
                    # mirror (x, y, xmin(ymin), xmax(ymax), dir)
                    mirrors.append((x - 0.5, None, y - 0.5, y + 0.5, 1))
                if downMirror(x, y, hall):
                    mirrors.append((x + 0.5, None, y - 0.5, y + 0.5, -1))
                if leftMirror(x, y, hall):
                    mirrors.append((None, y - 0.5, x - 0.5, x + 0.5, 1))
                if rightMirror(x, y, hall):
                    mirrors.append((None, y + 0.5, x - 0.5, x + 0.5, -1))
    return mirrors

def isSeeableCorner(X, corner, blindPoints, mirror):
    x, y = X
    cx, cy = corner[0]
    dirx, diry = corner[1]
    if (x - cx) * dirx <= 0 or (x - cy) * diry <= 0:
        return False
    if mirror:
        mx = mirror[0]
        my = mirror[1]
        if mx is not None:
            if cx != x:
                iy = cy + (mx - cx) * (y - cy) / (x - cx)
                if iy < mirror[3] and iy > mirror[4]:
                    return False
        elif my is not None:
            if cy != y:
                ix = cx + (my - cy) * (x - cx) / (y - cy)
                if ix < mirror[3] and ix > mirror[4]:
                    return False
    # TODO: block
        
    # TODO: blindPoints
    #A = 
    return True
    
def getMirrorCorner(mirror, corner):
    mx = mirror[0]
    my = mirror[1]
    dirm = mirror[4]
    cx, cy = corner[0]
    dirx, diry = corner[1]
    if mx is not None:
        if dirm == dirx or (cx - mx) * dirm <= 0:
            return None
        mcx = mirror[0] * 2 - cx
        mcy = cy
        mcdirx = -dirx
        mcdiry = diry
    elif my is not None:
        if dirm == diry or (cy - my) * dirm <= 0:
            return None
        mcx = cx
        mcy = mirror[1] * 2 - cy
        mcdirx = dirx
        mcdiry = -diry
    return ((mcx, mcy), (mcdirx, mcdiry))

def isClose(D, X, C):
    return 4 * ((X[0] - C[0]) ** 2 + (X[1] - C[1]) ** 2) <= D ** 2

def isDirectClose(D, X, C):
    return (X[0] - C[0]) ** 2 + (X[1] - C[1]) ** 2 <= D ** 2

def populateCorners(D, X, hall, corners, mirrors, blindPoints):
    populatedCornerMap = dict()
    toPopulateCornerMap = dict()
    for corner in corners:
        toPopulateCornerMap[corner] = isSeeableCorner(X, corner, hall, None)

    while toPopulateCornerMap:
        corner, see = toPopulateCornerMap.popitem()
        populatedCornerMap[corner] = see
        for mirror in mirrors:
            mirrorCorner = getMirrorCorner(mirror, corner)
            #print corner, mirror, mirrorCorner
            if not mirrorCorner or not isClose(D, X, mirrorCorner[0]):
                continue    
            see = isSeeableCorner(X, mirrorCorner, hall, mirror)
            #print "valid"
            if mirrorCorner in populatedCornerMap:
                if see and not populatedCornerMap[mirrorCorner]:
                    populatedCornerMap[mirrorCorner] = see
            elif mirrorCorner in toPopulateCornerMap:
                if see and not toPopulateCornerMap[mirrorCorner]:
                    toPopulateCornerMap[mirrorCorner] = see
            else:
                toPopulateCornerMap[mirrorCorner] = see
        #print bool(toPopulateCornerStack), toPopulateCornerStack
    return populatedCornerMap
    
def getDistance(D, X, hall, dx, dy):
    x = X[0]
    y = X[1]
    d = 0
    while hall.get((x, y)) != "#":
        x += dx
        y += dy
        d += 1
    return 1 if 2 * d - 1 <= D else 0

def xInMirrors(D, X, hall):
    result = 0
    result += getDistance(D, X, hall, -1, 0)
    result += getDistance(D, X, hall, 1, 0)
    result += getDistance(D, X, hall, 0, -1)
    result += getDistance(D, X, hall, 0, 1)
    return result

def solve(H, W, D, X, hall):
    blindPoints = getBlindPoints(H, W, X, hall)
    blindPoints = list()
    mirrors = getMirrors(H, W, hall)
    print "mirrors: ", mirrors
    corners = getCorners(H, W, D, X, hall)
    print "corners: ", corners
    populatedCornerMap = populateCorners(D, X, hall, corners, mirrors, blindPoints)
    result = xInMirrors(D, X, hall)
    print len(populatedCornerMap), populatedCornerMap
    for corner, see in populatedCornerMap:
        if see:
            result += 1
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
        result = solve(H, W, D, X, hall)
        outFile.write("Case #%d: %s\n" % (i + 1, result))
    endTime = datetime.datetime.now()

    print SEPARATE_LINE
    print "End Time = %s" % endTime
    print "Cost Time = %s" % (endTime - startTime)
    inFile.close()
    outFile.close()
