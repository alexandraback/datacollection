from __future__ import print_function
import sys

# print to stderr for debugging
enableDebug = True
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
    N = int(next(linesIter))
    friends = [int(x)-1 for x in next(linesIter).split(" ")]

    # Find lonely children
    lonelyKids = set()
    nBestIncoming = [0]*N
    for i in range(N):
        nBestIncoming[friends[i]] += 1
    for i in range(N):
        if nBestIncoming[i] == 0:
            lonelyKids.add(i)

    printe("Lonely kids = " + str(lonelyKids))

    # Count the pairs
    nPairs = 0
    pairID = [-1]*N
    for i in range(N):
        if i == friends[friends[i]]:
            nPairs += 1
            pairID[i] = i
            pairID[friends[i]] = i

    printe("pairIDs = " + str(pairID))

    # Create lists of freestrings by pairID
    freeStrs = {}
    for i in range(N):
        if pairID[i] != -1:
            freeStrs[i] = []

    # Find freestrings
    bestFreeStrLen = [0]*N
    for startI in lonelyKids: 

        strLen = 0
        currI = startI
        seen = set()
        while True:

            if pairID[currI] != -1:
                isFree = True
                termPair = currI
                break

            if currI in seen:
                isFree = False
                break
            seen.add(currI)

            currI = friends[currI]
            strLen += 1

        if isFree:
    
            newBest = True
            oldBestNum = -1
            for n in seen:
                if bestFreeStrLen[n] > strLen:
                    newBest = False
                if bestFreeStrLen[n] < strLen and bestFreeStrLen[n] != 0:
                    oldBestNum = bestFreeStrLen[n]

            if newBest:
                if oldBestNum != -1:
                    freeStrs[termPair].remove(oldBestNum)
                freeStrs[termPair].append(strLen)

                for n in seen:
                    bestFreeStrLen[n] = strLen



    # Find the length of the best free solution
    freeStringSum = 0
    for pairKey in range(N):
        if pairKey in freeStrs:
            freeStrs[pairKey].sort()
            freeStrs[pairKey].reverse()

            printe("  pairKey " + str(pairKey))
            printe("  pairKeyFreestrs " + str(freeStrs[pairKey]))
            printe("  freeStringSum " + str(freeStringSum))

            freeStringSum += 1
            printe("  freeStringSum " + str(freeStringSum))
            if len(freeStrs[pairKey]) >= 1:
                freeStringSum += freeStrs[pairKey][0]
            printe("  freeStringSum " + str(freeStringSum))



    # Find the longest cycle
    touched = [False]*N
    longestCycle = -1

    while True:

        currInd = -1
        for i in range(N):
            if not touched[i]:
                currInd = i
                break
        
        printe("\n Starting search cycle...")

        if currInd == -1:
            break


        count = [-1]*N
        itCount = 0
        cycleLen = -1

        while True:

            printe("    currInd = " + str(currInd))

            if(count[currInd] != -1):
                cycleLen = itCount - count[currInd]
                printe(count)
                printe(cycleLen)
                break
            
            if touched[currInd]:
                break

            touched[currInd] = True

            count[currInd] = itCount
            itCount += 1
            currInd = friends[currInd]

        longestCycle = max((longestCycle, cycleLen))


    solution = max(freeStringSum, longestCycle)

    print("Case #{}: {}".format(iCase, solution))
