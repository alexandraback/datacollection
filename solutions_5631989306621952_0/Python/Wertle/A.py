from __future__ import print_function
import sys

# print to stderr for debugging
# enableDebug = True 
enableDebug = False 
def printe(*stuff):
    if enableDebug:
        print(*stuff, file=sys.stderr) 


# Open file for processing
filename = sys.argv[1]
inputFile = open(filename, 'r')
lines = [l.rstrip('\n') for l in inputFile]
linesIter = iter(lines)
nCases = int(linesIter.next())


# Process each case
for iCase in range(1,nCases+1):
    printe("\nProcessing case " + str(iCase))

    # Solve problem
    outStr = ''
    letters = list((next(linesIter)))

    startStr = ''
    endStr = ''

    while len(letters) > 0:
        
        lastInd = -1
        lastChar = 'A'
        for j in range(len(letters)):
            if letters[j] >= lastChar:
                lastChar = letters[j]
                lastInd = j

        startStr = startStr + letters[lastInd]
        newEndStr = ''
        for j in range(lastInd+1, len(letters)):
            newEndStr += letters[j]
        endStr = newEndStr + endStr

        letters = letters[:lastInd]

        printe("lastChar = " + str(lastChar))


    outStr = startStr + endStr

    print("Case #{}: {}".format(iCase, outStr))
