import time
#import math
#import sys
#import fractions

debug = True
inFile = "B-small-attempt0.in"
outFile = inFile.rstrip(".in") + ".out"

def monkeys(testNum, fin):
    dbgPrint("")
    
    dbgPrint("Test %d" % testNum)
    dbgPrint("----------")
    
    numKeys, targetLen, numStrokes = fin.readline().rstrip("\n").split(" ")
    dbgPrint(numKeys)
    dbgPrint(targetLen)
    dbgPrint(numStrokes)
    numKeys = int(numKeys)
    targetLen = int(targetLen)
    numStrokes = int(numStrokes)
    
    keysStr = fin.readline().rstrip("\n")
    dbgPrint(keysStr)
    
    targetWord = fin.readline().rstrip("\n")
    dbgPrint(targetWord)
    
    for l in targetWord:
        if l not in keysStr:
            return 0
    
    takingBananas = 0
    
    banTest = targetWord*(numStrokes//targetLen)
    banTest += targetWord[0:numStrokes%targetLen]
    dbgPrint(banTest)
    for i in range(numStrokes-targetLen+1):
        if banTest[i:targetLen+i] == targetWord:
            takingBananas += 1
    
    dbgPrint(takingBananas)
    
    keyDict = {}
    for k in keysStr:
        if k in keyDict:
            keyDict[k] += 1.0
        else:
            keyDict[k] = 1.0
    
    dbgPrint(keyDict)
    
    chance = 1.0
    for k in targetWord:
        chance *= (keyDict[k]/numKeys)
    
    dbgPrint(chance)
    
    return round((1-chance)*takingBananas,7)

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
        
        number = monkeys(testNum, fin)
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
