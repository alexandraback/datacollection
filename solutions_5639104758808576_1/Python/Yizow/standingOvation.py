import sys



def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())

            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                sMax, levels = inputFile.readline().split()
                sMax = int(sMax)
                invitesNeeded = calcInvites(sMax, levels)
                outputFile.write("Case #%d: %d" % (testNum+1, invitesNeeded))

def calcInvites(sMax, levels):
    numPeople = 0
    invites = 0
    for shyness in range(sMax+1):
        additional = shyness - numPeople
        if additional < 0:
            additional = 0
        invites += additional
        # print "shyness %d thisLevel %d numPeople %d additional %d" % (shyness, int(levels[shyness]), numPeople, additional)
        numPeople += int(levels[shyness])
        numPeople += additional

    return invites


def sumStringDigits(s):
    total = 0
    for char in s:
        total += ord(char)-48
    return total



main()