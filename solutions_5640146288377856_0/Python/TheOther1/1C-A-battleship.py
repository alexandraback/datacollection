import time
#import math
#import sys
#import fractions

debug = True
inFile = "A-small-attempt0.in"
outFile = inFile.rstrip(".in") + ".out"

def battleship(testNum, fin):
    dbgPrint("")
    
    dbgPrint("Test %d" % testNum)
    dbgPrint("----------")
    
    rows, cols, ship = fin.readline().rstrip("\n").split(" ")
    dbgPrint(rows)
    dbgPrint(cols)
    dbgPrint(ship)
    rows = int(rows)
    cols = int(cols)
    ship = int(ship)
    
    shots = (cols//ship) + (ship-1)
    if cols%ship != 0:
        shots += 1
        
    return shots

def dbgPrint(string):
    if debug:
        print(string)

def go():
    fin = open(inFile, "rU")
    fout = open(outFile, "w")
    
    numTests = int(fin.readline())
    print("Number of tests = %d" % numTests)
    
    programStartTime = time.clock()
    
    for testNum in range(1,numTests+1):
        caseStartTime = time.clock()
        
        number = battleship(testNum, fin)
        outStr = "Case #%d: %s" % (testNum, number)
        
        print("%s" % outStr)
        fout.write("%s\n" % outStr)
        
        caseEndTime = time.clock()
        print("time = %s" % (caseEndTime - caseStartTime))
    
    programEndTime = time.clock()
    print("Total time = %s" % (programEndTime - programStartTime))
    
    fout.close()
    fin.close()

if __name__ == "__main__":
    go()
