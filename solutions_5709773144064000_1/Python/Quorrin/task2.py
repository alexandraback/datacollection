

infile = open("input.in")
lines = infile.read().split('\n')
numCases = int(lines[0])
lines = lines[1:]
infile.close()

infile.close()
outputFile = open('output.out','w')
for i in range(numCases):
    data = map(float,lines[i].split(' '))
    bestTime = 1000000
    currentBestTime = 1000000

    currentTime = 0.0
    numFarms = 0
    C = data[0]
    F = data[1]
    X = data[2]
    productionRate = 2.0

    faster = True

    while(faster):
        currentBestTime = X/productionRate + currentTime
        
        if(currentBestTime < bestTime):
            bestTime = currentBestTime
        else:
            faster = False

        currentTime += C/productionRate
        numFarms += 1
        productionRate += F
    outputFile.write("Case #" + str(i+1) + ": " + str(bestTime) + "\n")

outputFile.close()
        
        
