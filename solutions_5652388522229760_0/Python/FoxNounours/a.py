#/usr/bin/python3

import sys

def fillDigits(x, digitSet) :
    while x > 0 :
        digitSet.add(x % 10)
        x = x//10
        
inputFile = open("input", "r")
outputFile = open("output", "w")
caseNb = 1

inputLine = inputFile.readline()
T = int(inputLine)

for inputLine in inputFile :

    result = 0
    #here
    digitSet = set()
    Y = int(inputLine)
    if Y == 0 :
        result = "INSOMNIA"
    else :
        while len(digitSet) < 10 :
            result += Y
            fillDigits(result, digitSet)
    
    outputFile.write("Case #{0}: {1}\n".format(caseNb, result));

    caseNb += 1

inputFile.close()
outputFile.close()
