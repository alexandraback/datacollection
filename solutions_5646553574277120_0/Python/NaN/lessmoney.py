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
        textToParse = lineText[0:-1]
        inputParams = textToParse.split(" ")
        C = int(inputParams[0]) # maximum number of coins of one denomination to be used
        D = int(inputParams[1]) # number of denominations
        V = int(inputParams[2]) # maximum value purchaseable by new rules
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
        denomOld = list(map(int, textToParse.split(" ")))
        denomOld.sort()
        Vcurrent = 0
        DnextPos = 0
        denomNewCount = 0
        while Vcurrent < V:
            if DnextPos < len(denomOld):
                if Vcurrent + 1 >= denomOld[DnextPos]:
                    Dcurrent = denomOld[DnextPos]
                    DnextPos += 1
                else:
                    denomNewCount += 1
                    Dcurrent = Vcurrent + 1
            else:
                denomNewCount += 1
                Dcurrent = Vcurrent + 1
            Vcurrent += Dcurrent * C
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", denomNewCount, end="", sep="")