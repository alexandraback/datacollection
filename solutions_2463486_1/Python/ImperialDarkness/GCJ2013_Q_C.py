import re

# function that checks if an int is a palindrome
# O(n) / n = len(#)
def isPalindrome(integer):
    x = str(integer)

    length = len(x)
    for i in range (0, len(x)/2) :
        if (x[i] != x[length - i - 1]) :
            return False
    return True
"""
def testInt(i):
    if not isPalindrome(i):
        return False
    iSqr = i*i
    print iSqr
    if isPalindrome(iSqr):
        return True
    return False

"""

totalCases = 0
caseNumber = 0
name = "C-large-1"

minN = pow(10, 0)
maxN = pow(10, 14)

import math

minSqrt = int(math.floor(math.sqrt(minN))) - 1
maxSqrt = int(math.ceil(math.sqrt(maxN))) + 1


c = [0] * 100
ci = 0
for i in range(minSqrt, maxSqrt):
    if isPalindrome(i):
        iSqr = i*i
        if isPalindrome(iSqr) and iSqr >= minN and iSqr <= maxN:
            # print iSqr, i
            c[ci] = iSqr
            ci+=1
masterList = c[:ci] # cutoff unused sections


inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0

for line in inFile:
    if (lineNumber == 0):
        # first line input (totalCases)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        minA = int(row[0])
        maxB = int(row[1])

        outcome = 0
        for i in range(len(masterList)):
            if masterList[i] >= minA and masterList[i] <= maxB:
                outcome += 1
        
        caseOutput = "Case #%d: %d\n" % (caseNumber, outcome)
        outFile.write(caseOutput)
        #print caseOutput
            
        caseNumber += 1
        
    lineNumber += 1
    
if caseNumber != totalCases + 1:
    print 'error. number of cases do not match'
    
inFile.close()
outFile.close()



