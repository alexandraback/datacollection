
import string, os, time, sys
import sets

def GetNumRecycledPairs(num, min, max):
    numStr = str(num)
    othersFound = sets.Set()
    
    for i in range(1, len(numStr)):
        otherStr = numStr[i:] + numStr[:i]
        if otherStr[0] != '0':
            other = int(otherStr)
            if num < other and other <= max and min <= other:
                othersFound.add(other)
    return len(othersFound)


def HandleCase(f, caseIndex):
    caseline = f.readline().rstrip("\r\n")
    result = 0
    splitline = caseline.split(" ")

    A = int(splitline[0])
    B = int(splitline[1])
    for i in range(A, B+1):
        result += GetNumRecycledPairs(i, A, B)

    print "Case #%(count)d: %(r)d" % {"count":caseIndex, "r":result}


inputFile = sys.argv[1]
f = open(inputFile, "r")
numCases = int(f.readline())
for i in range(0, numCases):
    HandleCase(f, i+1)

