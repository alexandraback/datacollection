from collections import Counter
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
        textToParse = lineText.strip()
        cnter = Counter(textToParse)
        phoneNumberList = [0] * 10
        # There are multiple way to find the solution. This is one.
        # "Z" unique in "ZERO"
        phoneNumberList[0] = cnter["Z"]
        cnter["E"] -= cnter["Z"]
        cnter["R"] -= cnter["Z"]
        cnter["O"] -= cnter["Z"]
        cnter["Z"] = 0
        # "X" unique in "SIX"
        phoneNumberList[6] = cnter["X"]
        cnter["S"] -= cnter["X"]
        cnter["I"] -= cnter["X"]
        cnter["X"] = 0
        # "W" unique in "TWO"
        phoneNumberList[2] = cnter["W"]
        cnter["T"] -= cnter["W"]
        cnter["O"] -= cnter["W"]
        cnter["W"] = 0
        # "G" unique in "EIGHT"
        phoneNumberList[8] = cnter["G"]
        cnter["E"] -= cnter["G"]
        cnter["I"] -= cnter["G"]
        cnter["H"] -= cnter["G"]
        cnter["T"] -= cnter["G"]
        cnter["G"] = 0
        # now "H" unique in "THREE"
        phoneNumberList[3] = cnter["H"]
        cnter["T"] -= cnter["H"]
        cnter["R"] -= cnter["H"]
        cnter["E"] -= cnter["H"]
        cnter["H"] = 0
        # "U" unique in "FOUR"
        phoneNumberList[4] = cnter["U"]
        cnter["F"] -= cnter["U"]
        cnter["O"] -= cnter["U"]
        cnter["R"] -= cnter["U"]
        cnter["U"] = 0
        # now "F" unique in "FIVE"
        phoneNumberList[5] = cnter["F"]
        cnter["I"] -= cnter["F"]
        cnter["V"] -= cnter["F"]
        cnter["E"] -= cnter["F"]
        cnter["F"] = 0
        # now "V" unique in "SEVEN"
        phoneNumberList[7] = cnter["V"]
        cnter["S"] -= cnter["V"]
        cnter["E"] -= cnter["V"]
        cnter["N"] -= cnter["V"]
        cnter["V"] = 0
        # now "O" unique in "ONE"
        phoneNumberList[1] = cnter["O"]
        cnter["N"] -= cnter["O"]
        cnter["E"] -= cnter["O"]
        cnter["O"] = 0
        # remaining letters must be for "NINE"
        phoneNumberList[9] = cnter["I"]
        phoneNumber = "".join([str(aNumber) * phoneNumberList[aNumber] for aNumber in range(10)])
        if i == 0:
            startCharacter = ""
        else:
            startCharacter = "\n"
        print(startCharacter, "Case #", i+1, ": ", phoneNumber, end="", sep="")