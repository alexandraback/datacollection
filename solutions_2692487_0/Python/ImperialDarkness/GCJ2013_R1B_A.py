import re
import math

totalCases = 0
caseNumber = 0
name = "A-small-attempt3"
#name = 'test'

caseL = 0

inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0

A = 0
N = 0
motes = []

def numAddsReq(current, required):
    n = (math.ceil(1.0*(required-current)/(current-1))+1)*0.5
    n = int(math.ceil(math.log(n, 2)))+1
    # verify
    newVal = valueAfterAdd(current, n)
    if newVal <= required:
       while newVal <= required:
           #print 'rounding correction up'
           n+=1
           newVal = valueAfterAdd(current, n)
    else: #newVal >= required
        while valueAfterAdd(current, n-1) > required and n > 2:
            #print current, n-1, valueAfterAdd(current, n-1), required
            #print 'rounding correction down'
            n -= 1

    return n

def valueAfterAdd(initial, times):
    ar = initial - 1
    totalAdded = ar * int(math.pow(2, times)-1)
    
    return initial + totalAdded

for line in inFile:
    if (lineNumber == 0):
        # first line input (L D N)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        if lineNumber % 2 == 1:
            A = int(row[0])
            N = int(row[1])
        else:
            outcome = 0
            motes = map(int, row)
            motes.sort()
            MAXX = len(motes)
            minSoFar = MAXX # absolute max possible
            size = A
            addsSoFar = 0
            for i in range(len(motes)):
                sizeBefore = size
                if size <= 1:
                    addsSoFar = MAXX
                    break
                if size > motes[i]:
                    size += motes[i]
                    print sizeBefore, motes[i], size
                    continue
                # less than the current size
                # check if remove all
                minSoFar = min([minSoFar, len(motes)-i + addsSoFar])
                addsReq = numAddsReq(size, motes[i])
                addsSoFar += addsReq
                minSoFar = min([minSoFar, addsReq])
                if addsReq > len(motes)-i:
                    addsSoFar = MAXX
                    #print '%d adds required, but only %d to remove' % (addsReq, len(motes)-i)
                    break
                size = valueAfterAdd(size, addsReq)
                size += motes[i]
                
                #print sizeBefore, addsReq, motes[i], size
            outcome = min([minSoFar, addsSoFar])

            caseOutput = "Case #%d: %d\n" % (caseNumber, outcome)
            #print motes, A
            #print caseOutput
            outFile.write(caseOutput)
    
            caseNumber += 1

    lineNumber+=1
    
inFile.close()
outFile.close()

print 'complete'



