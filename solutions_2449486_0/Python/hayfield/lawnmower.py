
f = open('B-small-attempt2.in', 'r')

# read in test count
line = f.readline()
numInputs = int(line)

results = [True] * numInputs

# process tests
currentInput = 0
while currentInput < numInputs:
    line = f.readline()
    splitLine = line.split()
    numRows = int(splitLine[0])
    numCols = int(splitLine[1])

    # get the desired lawn config
    lawn = []
    currentRow = 0
    while currentRow < numRows:
        # read in row data
        line = f.readline()
        splitLine = line.split()

        # convert from strings to ints
        currentCol = 0
        while currentCol < numCols:
            splitLine[currentCol] = int(splitLine[currentCol])
            currentCol += 1

        lawn.append(splitLine)

        currentRow += 1

    # check to see if the config is possible
    # find the max values in each column
    colCache = [0] * numCols
    currentCol = 0
    while currentCol < numCols:
        maxValInCol = 0
        currentRow = 0
        while currentRow < numRows:
            if lawn[currentRow][currentCol] > maxValInCol:
                maxValInCol = lawn[currentRow][currentCol]
                colCache[currentCol] = maxValInCol
            currentRow += 1
        currentCol += 1

    # go through each row
    currentRow = 0
    while currentRow < numRows:
        # find the max value in a row
        maxValInRow = max(lawn[currentRow])

        # do a pass through the row, finding any values shorter than the max
        # if they are shorter, check to see whether all values in the corresponding column are smaller
        currentCol = 0
        while currentCol < numCols:
            if lawn[currentRow][currentCol] < maxValInRow and lawn[currentRow][currentCol] < colCache[currentCol]:
                results[currentInput] = False
                # break out of a couple of loops
                currentCol = numCols
                currentRow = numRows

            currentCol += 1

        currentRow += 1

    currentInput += 1

# output results
currentInput = 0
while currentInput < numInputs:
    if results[currentInput] is True:
        res = "YES"
    else:
        res = "NO"
    print "Case #" + str(currentInput + 1) + ": " + res

    currentInput += 1

f.close()
