#/usr/bin/python3

import sys

inputFile = open("input", "r")
outputFile = open("output", "w")
caseNb = 1

inputLine = inputFile.readline()
T = int(inputLine)

for inputLine in inputFile :

    #here
    result = inputLine[0]

    for i in range(1,len(inputLine)) :
        if inputLine[i] >= result[0] :
            result = inputLine[i] + result
        else :
            result += inputLine[i]
    
    outputFile.write("Case #{0}: {1}".format(caseNb, result));

    caseNb += 1

inputFile.close()
outputFile.close()
