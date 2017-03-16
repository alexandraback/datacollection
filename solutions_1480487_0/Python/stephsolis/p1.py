def printable(_set):
    out = ""
    for x in _set:
        out += str(x) + " "
    return out

def sum(_set):
    out = 0
    for x in _set:
        out += x
    return out

def sumPoints(judgePts, X, audiencePts):
    points = []
    for i in range(len(judgePts)):
        points.append(judgePts[i] + (X * audiencePts[i]))
    return sum(points)

def minPos(judgePts, X, audiencePts):
    points = []
    for i in range(len(judgePts)):
        points.append(judgePts[i] + (X * audiencePts[i]))
    pointsSrt = sorted(points)
    minVal = pointsSrt[0]
    out = []
    for x in range(len(points)):
        if points[x] == minVal:
            out.append(x)
    return out

def secMinPos(judgePts, X, audiencePts):
    points = []
    for i in range(len(judgePts)):
        points.append(judgePts[i] + (X * audiencePts[i]))
    pointsSrt = sorted(points)
    minVal = pointsSrt[0]
    secMinVal = pointsSrt[0]
    for i in range(len(points)):
        if points[i] > minVal:
            secMinVal = points[i]
            break
    
    return points.index(secMinVal)

inFile = open("in.txt")
outFile = open("out.txt", 'w')

numCases = int(inFile.readline())
for i in range(1, numCases+1):
    currLine = inFile.readline().strip()
    
    judgePts = currLine.split()[1::]
    for x in range(len(judgePts)):
        judgePts[x] = int(judgePts[x])
    X = sum(judgePts)
    audiencePts = [0] * len(judgePts)
    numContestants = len(judgePts)
    
    while sum(audiencePts) < 1:
        _min = minPos(judgePts, X, audiencePts)
        _secMin = secMinPos(judgePts, X, audiencePts)
        diff = (judgePts[_secMin] + (X * audiencePts[_secMin])) - (judgePts[_min[0]] + (X * audiencePts[_min[0]]))
        left = (1 - sum(audiencePts))
        if _secMin in _min:
            for x in _min:
                audiencePts[x] += left / numContestants
            break
        if diff * len(_min) <= left:
            for x in _min:
                audiencePts[x] += diff
        else:
            for x in _min:
                audiencePts[x] += left / numContestants
            break
    
    outFile.write("Case #" + str(i) + ": " + printable(audiencePts).strip() + '\n')