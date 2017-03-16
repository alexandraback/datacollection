def grassShorterOrEqualInColumn(lawnState, lawnColumns, row, value):
    for column in range(lawnColumns):
        if lawnState[row][column] > value:
            return False
    return True

def grassShorterOrEqualInRow(lawnState, lawnRows, column, value):
    for row in range(lawnRows):
        if lawnState[row][column] > value:
            return False
    return True
    

def lawnMower(lawnState, lawnRows, lawnColumns):
    for row in range(lawnRows):
        for column in range(lawnColumns):
            value = lawnState[row][column]
            if grassShorterOrEqualInColumn(lawnState, lawnColumns, row, value) or grassShorterOrEqualInRow(lawnState, lawnRows, column, value):
                continue
            else:
                print "This cell doesn't work!" + str(row) + str(column)
                return "NO"
    return "YES"

def run(inputFile, outputFile = "output.txt"):

    reader = open(inputFile)
    writer = open(outputFile, 'w')
    caseCounter = 1
    rowCounter = 0
    lawnState = []
    
    for line in reader.readlines()[1:]:

        line = line.strip()

        if rowCounter == 0:
            lawnState = []
            dimensionsOfLawn = line.split()
            rowCounter = int(dimensionsOfLawn[0])
            continue

        lawnRow = []
        for token in line.split():
            lawnRow.append(int(token))

        lawnState.append(lawnRow)
        rowCounter = rowCounter - 1

        if rowCounter == 0:
            print lawnState
            writer.write("Case #" + str(caseCounter) + ": " + lawnMower(lawnState, int(dimensionsOfLawn[0]), int(dimensionsOfLawn[1])) + "\n")
            caseCounter = caseCounter + 1
    print "Program completed successfully. Look at " + outputFile + " for output"
        
    
