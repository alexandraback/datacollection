from __future__ import print_function
import sys

# print to stderr for debugging
enableDebug = True
def printe(*stuff):
    if enableDebug:
        print(*stuff, file=sys.stderr) 


# Open file for processing
filename = sys.argv[1]
inputFile = open(filename, 'r')
lines = [l.rstrip('\n') for l in inputFile]
linesIter = iter(lines)
nCases = int(linesIter.next())


patternLength = -1
nLevels = -1
nStudents = -1


def nextLevelIndex(currIndex, pathChoice):
    nBefore = currIndex
    return patternLength*nBefore + pathChoice


# Process each case
for iCase in range(1,nCases+1):
    printe("\nProcessing case " + str(iCase))

    # Solve problem
    vals = [int(x) for x in next(linesIter).split(" ")]
    patternLength = vals[0]
    nLevels = vals[1]
    nStudents = vals[2]


    # Check for impossibility
    if(nLevels * nStudents < patternLength):
        print("Case #{}: {}".format(iCase, "IMPOSSIBLE"))
        continue

   
    # Each student tests nLevels consecutive tiles from the original pattern
    studentTestInds = []
    for startTile in range(0, patternLength, nLevels):

        currIndex = 0
        for iTileChoice in range(startTile, startTile + nLevels):
            currIndex = nextLevelIndex(currIndex, min((iTileChoice, patternLength-1)))


        # Switch to 1-indexing to output the answer
        studentTestInds.append(currIndex+1)
    

    indStrings = [str(x) for x in studentTestInds]
    print("Case #{}: {}".format(iCase, " ".join(indStrings))) 
