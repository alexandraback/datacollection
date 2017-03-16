import re

totalCases = 0
caseNumber = 0
caseL = 0
grid = [[]]*4


inFile = file("A-large.in","r")
outFile = open("A-large.out", "w")
lineNumber = 0

def subVal(old):
    if old == 'X':
        return 2
    if old == 'T':
        return 6
    if old == 'O':
        return 3
    else:
        return 0

for line in inFile:
    if (lineNumber == 0):
        # first line input (L D N)
        row = str(line).strip().split()
        totalCases = int(row[0])
        caseNumber = 1
    else:
        if caseL != 4:
            trimmedData = str(line).strip()
            grid[caseL] = list(trimmedData)
            #print trimmedData
            
        caseL += 1
        
        if caseL == 4:
            outcome = ''
            for i in range(4):
                for j in range(4):
                    grid[i][j] = subVal(grid[i][j])

            #print grid
            totalProd = 1 # to check for draw vs not complete
            for i in range(4):
                prod = 1
                prod2 = 1
                
                for j in range(4):
                    prod *= grid[i][j]
                    prod2 *= grid[j][i]

                totalProd *= prod
                #print prod, prod2
                if (prod % 16 == 0 and prod != 0) or (prod2 % 16 == 0 and prod2 != 0):
                    outcome = 'X won'
                    break
                elif (prod % 81 == 0 and prod != 0) or (prod2 % 81 == 0 and prod2 != 0):
                    outcome = 'O won'
                    break
                
            # not yet determined, try diagonals
            if outcome == '':
                prod = 1
                prod2 = 1
                for i in range(4):
                    prod *= grid[i][i]
                    prod2 *= grid[i][3-i]
                
                if (prod % 16 == 0 and prod != 0) or (prod2 % 16 == 0 and prod2 != 0):
                    outcome = 'X won'
                elif (prod % 81 == 0 and prod != 0) or (prod2 % 81 == 0 and prod2 != 0):
                    outcome = 'O won'

            if outcome == '':
                # still nothing, either a draw, incomplete
                if totalProd == 0 :
                    outcome = 'Game has not completed'
                else:
                    outcome = 'Draw'    

            caseOutput = "Case #%d: %s\n" % (caseNumber, outcome)
            #print caseOutput
            outFile.write(caseOutput)
            
            caseNumber += 1
        if caseL == 5:
            caseL = 0

    lineNumber+=1
    
inFile.close()
outFile.close()




