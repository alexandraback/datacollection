#inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

def minLine(list1, list2):
    return map(min, list1, list2)


def maxLine(list1, list2):
    return map(max, list1, list2)


def getXLine(data, x):
    for line in data:
        yield line[x]


def calcSingleTest2(f):
    line = f.readline()
    N = int(line.split()[0])
    M = int(line.split()[1])
    #    print str(N) + "  " + str(M)
    data = []
    minY = []
    minX = [100500] * M
    maxY = []
    maxX = [0] * M
    for y in xrange(N):
        line = f.readline()
        dataLine = map(int, line.split())
        minX = minLine(minX, dataLine)
        minY.append(min(dataLine))
        maxX = maxLine(maxX, dataLine)
        maxY.append(max(dataLine))
        data.append(dataLine)

    for y in xrange(N):
        for x in xrange(M):
            #if (data[y][x] > minX[x]) and (data[y][x] > minY[y]):
            if (data[y][x] < maxX[x]) and (data[y][x] < maxY[y]):
                return False
    return True


def checkRow(data, y, x, M, N):
    d = data[y][x]
    for i in xrange(M):
        if i <> x:
            if data[y][i] > d:
                return False
    return True


def checkColumn(data, y, x, M, N):
    d = data[y][x]
    for i in xrange(N):
        if i <> y:
            if data[i][x] > d:
                return False
    return True


def calcSingleTest(f):
    line = f.readline()
    N = int(line.split()[0])
    M = int(line.split()[1])
    #    print str(N) + "  " + str(M)
    data = []
    for y in xrange(N):
        line = f.readline()
        dataLine = map(int, line.split())
        data.append(dataLine)

    for y in xrange(N):
        for x in xrange(M):
            if not(checkRow(data, y, x, M, N)) and not checkColumn(data, y, x, M, N):
                return False
    return True

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------------------------------------------'
            res = calcSingleTest2(inpF)
            outF.write('Case #{0}: {1}\n'.format(i, ('YES' if res else 'NO')))
            #outF.write('Case #' + str(i) + ": " + ('YES' if res else 'NO'))




