import re
import math
from decimal import Decimal

totalCases = 0
caseNumber = 0
name = "B-large"
#name = 'test'

caseL = 0

inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0

N = 0
x = 0
y = 0

def pr(x, n):
    top = Decimal(math.factorial(n)/math.factorial(x))
    top *= Decimal(str(math.pow(0.5, n)));
    bottom = math.factorial(n-x)
    return top/bottom

def at_least(x, n):
    return sum(pr(i, n) for i in range(x, n+1))

for line in inFile:
    if (lineNumber == 0):
        # first line input (L D N)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        N = int(row[0])
        x = abs(int(row[1]))
        y = int(row[2])
        z = x + y

        upper = (z+1)*(z+2)/2
        lower = z/2*(z-1)
        
        if N >= upper:
            outcome = 1.0
        elif N <= lower:
            outcome = 0.0
        elif x == 0:
            outcome = 0.0
        else:
            NR = N - lower
            if z + y + 1 <= NR:
                outcome = 1.0
            else:
                outcome = at_least(y+1, NR)
        

        caseOutput = "Case #%d: %.8f\n" % (caseNumber, outcome)
        #print caseOutput
        outFile.write(caseOutput)
    
        caseNumber += 1

    lineNumber+=1
    
inFile.close()
outFile.close()

print 'complete'



