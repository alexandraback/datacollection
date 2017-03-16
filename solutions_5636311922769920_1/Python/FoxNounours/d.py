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

    if C == 1:
        if S < K:
            result = ' IMPOSSIBLE'
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
        else:
            for i in range(1,S+1):
                result += ' '+str(i)
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
        
    elif K%2 > 0 :
        if S < K//2+1 :
            result = ' IMPOSSIBLE'
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
        else:
            for i in range(0,K//2):
                result += ' '+str(2*i*K + 2*(i+1))
            result += ' '+str(K**C)
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
    else :
        if S < K//2 :
            result = ' IMPOSSIBLE'
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
        else:
            for i in range(0,K//2):
                result += ' '+str(2*i*K + 2*(i+1))
            outputFile.write("Case #{0}:{1}\n".format(caseNb, result))
            
    caseNb += 1

inputFile.close()
outputFile.close()
