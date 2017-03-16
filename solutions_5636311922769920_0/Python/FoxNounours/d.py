#/usr/bin/python3

import sys
        
inputFile = open("input", "r")
outputFile = open("output", "w")

inputLine = inputFile.readline()
T = int(inputLine)

caseNb = 1
for inputLine in inputFile :
    
    K = int(inputLine.split(' ')[0])
    C = int(inputLine.split(' ')[1])
    S = int(inputLine.split(' ')[2])

    result = ""
    
    for x in range(1,S+1):
        result += ' '+str(x)
    
    outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
    caseNb += 1

inputFile.close()
outputFile.close()
