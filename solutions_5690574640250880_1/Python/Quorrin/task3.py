import numpy as np

infile = open("input.in")
lines = infile.read().split('\n')
numCases = int(lines[0])
lines = lines[1:]
infile.close()

outputFile = open('output.out','w')

def writePoints(points):
    height = np.shape(points)[0]
    length = np.shape(points)[1]
    for i in range(height):
        line = ""
        for j in range(length):
            if(points[i][j] == 0):
                line += '.'
            elif(points[i][j] == -1):
                line += '*'
            else:
                line += 'c'
        outputFile.write(line+"\n")
        
    
    
def getInitialDimensions(size,bWidth,bLength):
    if (np.sqrt(1.0*size) > np.min((bWidth,bLength))):
        fWidth = np.min((bWidth,bLength))
    else:
        fWidth = int(np.round(np.sqrt(1.0*size)))
    return fWidth

for i in range(numCases):
    outputFile.write("Case #" + str(i+1) + ":\n")
    data = map(int,lines[i].split(' '))
    R = data[0]
    C = data[1]
    M = data[2] 
    width = 0
    length = 0
    extraTiles = 0
    points = np.zeros((R,C))
    points = points - 1
    replacementTileIndex = 0
    freeSpace = R * C - M
    #Edge cases
    if (freeSpace == 1):
        width = 1
        length = 1
    elif (freeSpace < 4):
        if (min(R,C) > 1):
            outputFile.write("Impossible\n")
            continue
        else:
            width = 1
            length = freeSpace
    elif (min(R,C) == 2):
        if (freeSpace % 2 == 1):
            outputFile.write("Impossible\n")
            continue
        else:
            width = 2
            length = freeSpace/2
    else:
        width = getInitialDimensions(freeSpace,R,C)
        length = int(np.floor(1.0*freeSpace/width))
        extraTiles = freeSpace%width
        #Only time you need to move freespace from other places
        if (extraTiles == 1):
            if (length < 3 or width < 3):
                outputFile.write("Impossible\n")
                continue
            else:
                replacementTileIndex = 1

    #paint cells
    if (C <= R):
        for i in range(length):
            for j in range(width):
                points[i][j] = 0
        for i in range(extraTiles):
            points[length][i] = 0
        if (replacementTileIndex == 1):
            points[length-1][width-1] = -1
            points[length][extraTiles] = 0
    else:
        for i in range(length):
            for j in range(width):
                points[j][i] = 0
        for i in range(extraTiles):
            points[i][length] = 0
        if (replacementTileIndex == 1):
            points[width-1][length-1] = -1
            points[extraTiles][length] = 0
    points[0][0] = 2
    writePoints(points)
        
outputFile.close()
