import math
import sys

if len(sys.argv) == 1:
    print("No input file provided.")
    sys.exit()
else:
    filename = sys.argv[1]
    try:
        fileobject = open(filename, 'r')
    except:
        print("Failed to open given file.")
        sys.exit()
    try:
        firstLine = fileobject.readline()
    except:
        print("Failed to read first line.")
        sys.exit()
    datasetSize = int(firstLine)
    if not datasetSize:
        print("Unable to parse dataset size.")
        sys.exit()
    lineNr = 1
    for i in range(datasetSize):
        lineNr = lineNr + 1
        try:
            lineText = fileobject.readline()
        except:
            print("Failed to read line ", lineNr)
            sys.exit()
        [cGiven, jGiven] = lineText.strip().split(" ")
        cImagine = []
        jImagine = []
        digitCount = len(cGiven)
        maxValue = 10 ** digitCount - 1
        minDiff = maxValue + 1
        minDiffNumbers = [0, maxValue]
        for cCurr in range(maxValue + 1):
            cCurrStr = str(cCurr).zfill(digitCount)
            validNumber = True
            for digitPos in range(digitCount):
                if cGiven[digitPos] != "?" and cGiven[digitPos] != cCurrStr[digitPos]:
                    validNumber = False
            if not validNumber:
                continue
            for jCurr in range(maxValue + 1):
                jCurrStr = str(jCurr).zfill(digitCount)
                validNumber = True
                for digitPos in range(digitCount):
                    if jGiven[digitPos] != "?" and jGiven[digitPos] !=jCurrStr[digitPos]:
                        validNumber = False
                if not validNumber:
                    continue
                currDiff = math.fabs(cCurr - jCurr)
                if currDiff < minDiff:
                    minDiff = currDiff
                    minDiffNumbers = [cCurrStr, jCurrStr]
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", minDiffNumbers[0], " ", minDiffNumbers[1], end="", sep="")