import decimal
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
        if lineText[-1] == "\n":
            textToParse = lineText[0:-1]
        else:
            textToParse = lineText
        inputParams = textToParse.split(" ")
        N = int(inputParams[0])
        sArray = inputParams[1:]
        for j in range(len(sArray)):
            sArray[j] = int(sArray[j])
        X = sum(sArray[:]) # sum of the point values of all contestants
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", end="", sep="")
        mArray = []
        alreadySafe = 0
        partSum = 0
        for aContestant in range(len(sArray)):
            if sArray[aContestant] >= 2 * X / N:
                alreadySafe += 1
            else:
                partSum += sArray[aContestant]
        for aContestant in range(len(sArray)):
            # The contestant gets eliminated, if all other contestants have more
            # points. They need the minimum points if they all have equal point Ji+X*Yi
            # So for si + X * Yi = contestant he or she doesn't get eliminated
            # So sum(si + X * Yi) for all i:
            # = X + X = 2X
            # => minTotalValue = 2X / N
            # mi = 2X / N - si
            if sArray[aContestant] >= 2 * X / N:
                mi = 0
            else:
                mi = ((X + partSum) / (N - alreadySafe) - sArray[aContestant]) / X * 100
            mArray.append(mi)
        M = sum(mArray)
        mCorrector = 100 / M
        isFirst = True
        for mi in mArray:
            if not isFirst:
                print(" ", end="", sep="")
            isFirst = False
            mi = mi * mCorrector
            print('%.6f' % round(mi,6), end="", sep="")