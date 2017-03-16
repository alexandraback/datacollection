import re
import math

totalCases = 0
caseNumber = 0
name = "A-small-attempt0"

caseL = 0

inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0



for line in inFile:
    if (lineNumber == 0):
        # first line input (L D N)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        r = int(row[0])
        t = int(row[1])
        outcome = 0
        """
        i = r
        t2 = t
        while True:
            reqT = (i+1)*(i+1)-i*i
            i+= 2
            t2 -= reqT
            if t2 <= 0:
                if t2 == 0:
                    outcome += 1
                print outcome
                break
            else:
                outcome += 1
        """

        a = 2
        b = 2*r - 1
        c = - t
        step = b * b - 4*a*c
        step = math.sqrt(step)
        final = - b + step
        final = final / 2 / a
        n = math.floor(final)
        
        n = int(n)

        for i in range(n - 2, n + 2):
            if a*i*i+ b*i + c <= 0:
                outcome = i
            else:
                break

        caseOutput = "Case #%d: %s\n" % (caseNumber, outcome)
        #print caseOutput
        outFile.write(caseOutput)
        
        caseNumber += 1

    lineNumber+=1
    
inFile.close()
outFile.close()




