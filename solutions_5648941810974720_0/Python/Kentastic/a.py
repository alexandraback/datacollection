import sys

def Remove(numberString, removeString):
    for i in range(0,len(removeString)):
        numberString = numberString.replace(removeString[i], '', 1)
    return numberString


inputStrings = open('A-small-attempt0.in', 'r').read().splitlines()
caseNum = int(inputStrings[0])
outString = ""

for case in range(1,caseNum+1):
    outString += "Case #" + str(case) + ": "
    num = []
    numStr = inputStrings[case]

    while 'Z' in numStr:
        num.append(0)
        numStr = Remove(numStr, "ZERO")

    while 'W' in numStr:
        num.append(2)
        numStr = Remove(numStr, "TWO")

    while 'U' in numStr:
        num.append(4)
        numStr = Remove(numStr, "FOUR")

    while 'X' in numStr:
        num.append(6)
        numStr = Remove(numStr, "SIX")

    while 'O' in numStr:
        num.append(1)
        numStr = Remove(numStr, "ONE")

    while 'F' in numStr:
        num.append(5)
        numStr = Remove(numStr, "FIVE")

    while 'V' in numStr:
        num.append(7)
        numStr = Remove(numStr, "SEVEN")

    while 'N' in numStr:
        num.append(9)
        numStr = Remove(numStr, "NINE")

    while 'R' in numStr:
        num.append(3)
        numStr = Remove(numStr, "THREE")

    while 'G' in numStr:
        num.append(8)
        numStr = Remove(numStr, "EIGHT")

    num.sort()
    for n in num:
        outString += str(n)

    outString += '\n'

fileOut = open('A-small-attempt0.out', 'w')
fileOut.write(outString)
fileOut.close()