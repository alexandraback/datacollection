import re

totalCases = 0
caseNumber = 0
caseL = 0
name = "B-large"

inFile = file("%s.in" % name,"r")
outFile = open("%s.out" % name, "w")
lineNumber = 0
x = 0
y = 0
grid = []

for line in inFile:
    if (lineNumber == 0):
        # first line input (totalCases)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        row = str(line).strip().split()
        if caseL == 0:
            x = int(row[0])
            y = int(row[1])
            grid = [[]]*x
        else:
            grid[caseL-1] = map(int, row)
            
        caseL += 1
        if caseL == x + 1:
            caseL = 0 # reset for next case
            

            possible = False
            
            while True:
                curMin = min(map(min, grid))

                rW = len(grid[0])
                rTotals = [sum(x) for x in grid]
                
                for i in range(len(rTotals)-1, -1, -1):
                    if rTotals[i] == rW * curMin:
                        # row trimmed, get rid of it
                        del grid[i]

                rH = len(grid)
                cTotals = [sum(x) for x in zip(*grid)]
                
                for i in range(len(cTotals)-1, -1, -1):
                    if cTotals[i] == rH * curMin:
                        # row trimmed, get rid of it
                        for j in range(rH):
                            del grid[j][i]
                
                if len(grid) == 0 or len(grid[0]) == 0:
                    possible = True
                    break
                if min(map(min, grid)) == curMin:
                    possible = False
                    break
            
            outcome = 'YES' if possible else 'NO'

            caseOutput = "Case #%d: %s\n" % (caseNumber, outcome)
            #print caseOutput
            outFile.write(caseOutput)
            
            caseNumber += 1
            
        
    lineNumber += 1
    
if caseNumber != totalCases + 1:
    print 'error. number of cases do not match'
    
inFile.close()
outFile.close()




