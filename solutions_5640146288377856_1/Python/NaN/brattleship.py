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
        textToParse = lineText[0:-1]
        inputParams = textToParse.split(" ")
        R = int(inputParams[0]) # rows of area
        C = int(inputParams[1]) # cols of area
        W = int(inputParams[2]) # length of ship
        # The ship is positioned horizontally (in a row).
        # Ask for positions of a row so the ship can't be placed there.
        # P = positions required to check for existence of ship in row.
        # C <= (P + 1) * (W - 1) + P
        # P >= (C - W + 1) / W = (C + 1) / W - 1
        P = math.ceil((C + 1) / W - 1)
        checks = P * R
        if C - (P - 1) * W == W:
            # There is only one free area left where the ship will be, so every
            # guess will be a hit.
            checks = checks - 1 + W
        elif C == W:
            checks += W - 1
        elif W > 1:
            # If there is room for missing the ship, we will miss it now once,
            # but know the complete position afterwards.
            # If the ship length is 1, we already have sunk it.
            checks = checks + 1 + W - 1
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", checks, end="", sep="")