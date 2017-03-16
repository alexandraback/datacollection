import sys
import math


def isPalindrome(num):
    numStr = str(num)
    reversedStr = numStr[::-1]
    return numStr == reversedStr


# find out how many inputs there are
line = sys.stdin.readline()
numInputs = int(line)

currentInput = 0

while currentInput < numInputs:
    numInInterval = 0
    line = sys.stdin.readline()
    splitLine = line.split()

    startVal = int(splitLine[0])
    endVal = int(splitLine[1])

    startBase = int(math.ceil(math.sqrt(startVal)))
    endBase = int(math.floor(math.sqrt(endVal)))

    currentVal = startBase

    while currentVal <= endBase:
        if isPalindrome(currentVal):
            squaredVal = currentVal * currentVal

            if isPalindrome(squaredVal):
                numInInterval += 1

        currentVal += 1

    print "Case #" + str(currentInput + 1) + ": " + str(numInInterval)

    currentInput += 1
