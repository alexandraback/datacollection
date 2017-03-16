import re
import math

totalCases = 0
caseNumber = 0
name = "B-small-attempt2"
#name = 'test'

caseL = 0

inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0

e = 0
r = 0
n = 0

def getGain(vis, startR, saveR):
    
    #print vis, startR, saveR
    maxV = max(vis)
    maxVindex = vis.index(maxV)

    canUseR = min(e, startR + r * maxVindex)
    usedR = max(0, canUseR - max(0, saveR - r * (len(vis)- maxVindex)))
    
    #print maxVindex, maxV, canUseR, usedR, usedR*maxV
    
    firstHalf = 0 if maxVindex == 0 else getGain(vis[0:maxVindex], startR, e)
    bottomHalf = 0 if maxVindex == len(vis) - 1 else getGain(vis[maxVindex +1: len(vis)], r, saveR)
    totalGain = firstHalf + bottomHalf + (usedR) * maxV
    
        
    return totalGain

for line in inFile:
    if (lineNumber == 0):
        # first line input (L D N)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        if lineNumber % 2 == 1:
            e = int(row[0])
            r = int(row[1])
            n = int(row[2])
        else:
            visx = map(int, row)
            outcome = getGain(visx, e, 0)

            caseOutput = "Case #%d: %s\n" % (caseNumber, outcome)
            #print caseOutput
            outFile.write(caseOutput)
        
            caseNumber += 1

    lineNumber+=1
    
inFile.close()
outFile.close()




