inFile = open("in2.txt")
outFile = open("out2.txt", 'w')

numCases = int(inFile.readline())
for i in range(1, numCases+1):
    line = inFile.readline().split()
    
    points = [0]*int(line[0])
    s = int(line[1])
    p = int(line[2])
    for n in range(len(points)):
        points[n] = int(line[n+3])
    
    numNormal = 0
    numSurprising = 0 
    
    for g in points:
        isNormal = False
        if (p-1) < 0:
            if p <= g:
                numNormal += 1
                isNormal = True
        else:
            if ((3*p)-2) <= g:
                numNormal += 1
                isNormal = True
        
        if not isNormal:
            if (p-2) < 0:
                if p <= g:
                    numSurprising += 1
            else:
                if ((3*p)-4) <= g:
                    numSurprising += 1
            
    if numSurprising > s:
        numSurprising = s
    
    outFile.write("Case #" + str(i) + ": " + str(numNormal + numSurprising) + '\n')