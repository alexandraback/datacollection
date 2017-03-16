inputFile = open("C-small-attempt0 (1).in", 'r')
outputFile = open("boxOutSmall.txt", 'w')
numTests = int(inputFile.readline())

def optimize(aList, bList):
    if len(aList) == 0 or len(bList) == 0:
        return 0
    nextA = aList[0]
    nextB = bList[0]
    numA = nextA[0]
    typeA = nextA[1]
    numB = nextB[0]
    typeB = nextB[1]
    if typeA == typeB:
        if numA > numB:
            return numB + optimize([(numA-numB,typeA)]+aList[1:],bList[1:])
        else:
            return numA + optimize(aList[1:],[(numB-numA,typeA)]+bList[1:])
    else:
        return max(optimize(aList[1:],bList), optimize(aList, bList[1:]))

for i in range(numTests):
    l = inputFile.readline().split()
    n = int(l[0])
    m = int(l[1])
    aLine = inputFile.readline().split()
    aList = []
    for k in range(len(aLine)/2):
        aList += [(int(aLine[k*2]), int(aLine[k*2+1]))]
    bLine = inputFile.readline().split()
    bList = []
    for k in range(len(bLine)/2):
        bList += [(int(bLine[k*2]), int(bLine[k*2+1]))]
    best = optimize(aList, bList)
    outputFile.write('Case #' + str(i+1) + ': ' + str(best) + '\n')
inputFile.close()
outputFile.close()
