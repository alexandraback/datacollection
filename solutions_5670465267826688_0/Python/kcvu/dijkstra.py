__author__ = 'caseyvu'

import sys, copy

def readInput(fileName):
    global inputData

    inputFile = open(fileName)
    inputFile.readline() # number of test cases
    oddLine = True
    for line in inputFile:
        if oddLine:
            _,repeat = [int(n) for n in line.strip().split(' ')]
            oddLine = False
        else:
            str = line.strip()
            data = []
            for s in str:
                data.append([1,s])
            inputData.append({'repeat':repeat, 'values':data})
            oddLine = True

def multiply(v1, v2):
    global multiplyMap
    key = v1[1] + v2[1]
    rawRes = multiplyMap[key]
    sign = rawRes[0] * v1[0] * v2[0]
    res = (sign,rawRes[1])
    return res

def equals(v1, v2):
    if v1[1] == v2[1] and v1[0] == v2[0]:
        return True
    return False

multiplyMap = {
    '11': (1,'1'),
    '1i': (1,'i'),
    '1j': (1,'j'),
    '1k': (1,'k'),
    'i1': (1,'i'),
    'j1': (1,'j'),
    'k1': (1,'k'),
    'ii': (-1,'1'),
    'ij': (1,'k'),
    'ik': (-1,'j'),
    'ji': (-1,'k'),
    'jj': (-1,'1'),
    'jk': (1,'i'),
    'ki': (1,'j'),
    'kj': (-1,'i'),
    'kk': (-1,'1')
}

def find(target,unitValues,totalNoOfUnits,startIndex):
    temp = [1,'1']
    startUnit = startIndex[0]
    
    a = (totalNoOfUnits - startUnit - 1) / 4
    if a > 1 :
        endUnit = totalNoOfUnits - (a-1)*4
    else:
        endUnit = totalNoOfUnits

    startingIndex = startIndex[1]
    for u in range(startUnit,endUnit):
        for p in range(startingIndex,len(unitValues)):
            temp = multiply(temp,unitValues[p])
            #print "p={0} -> value={1}, temp={2}".format(p,unitValues[p],temp)
            #compare = equals(target,temp)
            #print "compare: {0} and {1} -> {2}".format(target,temp,compare)
            if equals(target,temp):
                return (u,p)
        startingIndex = 0 # from 2nd unit onward, start from index 0
    return None

def multiplyList(unitValues,totalNoOfUnits,startIndex):
    temp = [1,'1']
    startUnit = startIndex[0]
    
    a = (totalNoOfUnits - startUnit - 1) / 4
    endUnit = totalNoOfUnits - a*4
    startingIndex = startIndex[1]
    for u in range(startUnit,endUnit):
        for p in range(startingIndex,len(unitValues)):
            temp = multiply(temp,unitValues[p])
        startingIndex = 0 # from 2nd unit onward, start from index 0
    return temp
    
def nextIndex(pos,unitLen,totalNoOfUnits):
    if pos[1] >= (unitLen -1):
        if pos[0] < totalNoOfUnits -1:
            return (pos[0]+1,0)
        return None
    else:
        return (pos[0],pos[1]+1)

inputData = []
readInput(sys.argv[1])

for i in range(len(inputData)):
    repeat = inputData[i]['repeat']
    unitData = inputData[i]['values']
    
    #print "Unit Data: {0}".format(unitData)

    result = False
    endIndexForI = find((1,'i'),unitData,repeat,(0,0))
    if endIndexForI is not None:
        #print 'First: {0} - {1}'.format((0,0),endIndexForI)
        startIndexForJ = nextIndex(endIndexForI,len(unitData),repeat)
        if startIndexForJ is not None:
            endIndexForJ = find((1,'j'),unitData,repeat,startIndexForJ)

            if endIndexForJ is not None:
                #print 'Second: {0} - {1}'.format(startIndexForJ,endIndexForJ)
                startIndexForK = nextIndex(endIndexForJ,len(unitData),repeat)
                if startIndexForK is not None:
                    endIndexForK = find((1,'k'),unitData,repeat,startIndexForK)

                    if endIndexForK is not None:
                        #print 'Third: {0} - {1}'.format(startIndexForK,endIndexForK)
                        startIndexToCheck = nextIndex(endIndexForK,len(unitData),repeat)
                        if startIndexToCheck is None:
                            result = True
                        else:
                            restValue = multiplyList(unitData,repeat,startIndexToCheck)
                            result = equals((1,'1'),restValue)

    resultText = 'YES' if result else 'NO'
    print "Case #{0}: {1}".format(i+1,resultText)

    #if i == 4:
    #    sys.exit(0)