import sys
import math


def isPalindrome(num):
    numStr = str(num)
    reversedStr = numStr[::-1]
    return numStr == reversedStr


maxVal = int(math.pow(10, 14))
maxSqrted = int(math.sqrt(maxVal))
print maxSqrted
cache = [0] * (maxSqrted + 1)

currentVal = 1
totalToHere = 0
while currentVal <= maxSqrted:
    if isPalindrome(currentVal):
        squaredVal = currentVal * currentVal

        if isPalindrome(squaredVal):
            totalToHere += 1

    cache[currentVal] = totalToHere
    currentVal += 1

print "ready for input"

# find out how many inputs there are
line = sys.stdin.readline()
numInputs = int(line)

currentInput = 0
results = [0] * 10000

while currentInput < numInputs:
    numInInterval = 0
    line = sys.stdin.readline()
    splitLine = line.split()

    startVal = int(splitLine[0])
    endVal = int(splitLine[1])

    startBase = int(math.ceil(math.sqrt(startVal)))
    endBase = int(math.floor(math.sqrt(endVal)))

    numInInterval = cache[endBase] - cache[startBase - 1]

    results[currentInput] = numInInterval

    currentInput += 1

currentInput = 0
while currentInput < numInputs:
    print "Case #" + str(currentInput + 1) + ": " + str(results[currentInput])
    currentInput += 1
