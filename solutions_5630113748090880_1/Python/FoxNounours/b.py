#/usr/bin/python3

import sys

inputFile = open("input", "r")
outputFile = open("output", "w")
caseNb = 1

inputLine = inputFile.readline()
T = int(inputLine)

for inputLine in inputFile :

    #here
    result = []
    N = int(inputLine)
    count = {}

    for i in range(0,N*2-1) :
        inputLine = inputFile.readline()
        l = inputLine.split();
        
        for x in l :
            if x in count.keys() :
                count[x] += 1
            else:
                count[x] = 1
    
    for k in count.keys() :
        if count[k] % 2 > 0 :
            result.append(k)

    resultInt = []
    for x in result :
        resultInt.append(int(x))
    resultInt.sort()
    
    if len(resultInt) > N :
        print("ho ho ho pb : N={0} result={1}".format(N, resultInt))
        
    resultstr = ""
    for x in resultInt :
        resultstr += " "+str(x)
    
    outputFile.write("Case #{0}:{1}\n".format(caseNb, resultstr));

    caseNb += 1

inputFile.close()
outputFile.close()
