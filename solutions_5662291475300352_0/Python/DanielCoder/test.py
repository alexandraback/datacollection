from fractions import gcd
from functools import reduce
from math import ceil
def naiveSolution(case):
    # [[degree, hikers, fastest]]
    hikersPosition = []
    hikers = case
    slowest = -1
    
    for hiker in hikers:
        if hiker[2] + (hiker[1] - 1) > slowest:
            slowest = (hiker[1] - 1) + hiker[2]

    #print(slowest)    
    for hiker in hikers:
        degree, num, fastestTime = hiker
        for i in range(num):
            currentTime = fastestTime + i
            tripsBack = ceil(slowest / currentTime)
            #print(tripsBack)
            for j in range(min(tripsBack, len(hikers))):
                #print("#")
                startAngle = degree - 360*j / (currentTime + i)
                endTime =(360 - startAngle) * (currentTime + i)
                hikersPosition.append([startAngle, endTime/360])
    lines = []
    ends = []
    #print (hikersPosition)
    for pos in hikersPosition:
        lines.append([(0, pos[0]), (pos[1], 360)])
        ends.append(pos[1] - 0.000000000000000000000001)
        ends.append(pos[1] + 0.000000000000000000000001)
    #print(lines)
    """print('close all; hold on')
    for line in lines:
        print('plot([%f %f], [%f %f]);' % (line[0][0], line[1][0], line[0][1], line[1][1]))
    """
    minInts = -1
    
    #print (lines)
    for end in ends:
        intersects = 0
        myLine = [(0, 0), (end, 360)]
        for line in lines:
            ints = line_intersection(myLine, line)
            if ints is None:
                continue
            x, y = ints
            #print((x,y))
            if x <= 0 or x > end or y <= 0 or y > 360:
                continue
            intersects += 1
        if minInts == -1:
            minInts = intersects

        minInts = min(minInts, intersects)
        
        
    return minInts
            
        
def line_intersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1]) #Typo was here

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       return None

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return x, y
def parseInput(text):
    cases = []
    lines = text.splitlines()
    currentlyAt = 1
    for i, line in enumerate(lines):
        if currentlyAt > i:
            continue
        currentlyAt = i + int(line) + 1
        vis = []
        for k in range(i+1, currentlyAt):
            vis.append(list(map(int, lines[k].split(' '))))
        

        cases.append((vis))
    return cases

def getOutput(solved):
    lines = []
    for i, solvedCase in enumerate(solved):
        lines.append("Case #%d: %d" % (i + 1, solvedCase))
    return '\n'.join(lines)

def generateOutput(filename, outFile = None):
    cases = getCases(filename)
    solvedCases = [naiveSolution(case) for case in cases]
    output = getOutput(solvedCases)
    if outFile == None:
        outFile = filename[:-2] + "out"
    with open(outFile, "w") as h:
        h.write(output)

    
def getCases(filename):
    with open(filename) as h:
        data = h.read()
    return parseInput(data)


def saveC(save = None):
    global cache
    with open("cache.obj", "wb") as h:
        pickle.dump(save if save is not None else cache, h)
def loadC():
    with open("cache.obj", "rb") as h:
        cache = pickle.load(h)
    return cache
