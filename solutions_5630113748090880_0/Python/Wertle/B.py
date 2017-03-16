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


# Process each case
for iCase in range(1,nCases+1):
    printe("\nProcessing case " + str(iCase))

    # Solve problem
    N = int(next(linesIter))

    numCount = [0]*3000

    for i in range(2*N-1):
        vals = next(linesIter).split(" ")
        for x in vals:
            numCount[int(x)] += 1

    result = []
    for i in range(3000):
        if (numCount[i] % 2) == 1:
            result.append(i)

    result.sort()
    # result.reverse()

    print("Case #{}: {}".format(iCase, " ".join([str(x) for x in result])))
    # print("Case #{}: {}".format(iCase, " ".join(result))
