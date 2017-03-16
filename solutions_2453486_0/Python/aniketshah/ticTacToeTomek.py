def hasWon(boardState, winningSymbol):

    # Horizontal Check
    for row in range(len(boardState)):
        rowWinner = True
        for column in range(len(boardState)):
            if boardState[row][column] == winningSymbol or boardState[row][column] == "T":
                continue
            else:
                rowWinner = False
                break
        if rowWinner == True:
            return True

    # Vertical Check
    for column in range(len(boardState)):
        columnWinner = True
        for row in range(len(boardState)):
            if boardState[row][column] == winningSymbol or boardState[row][column] == "T":
                continue
            else:
                columnWinner = False
                break
        if columnWinner == True:
            return True

    # Diagonal Check
    if (boardState[0][0] == winningSymbol or boardState[0][0] == "T") and (boardState[1][1] == winningSymbol or boardState[1][1] == "T") and (boardState[2][2] == winningSymbol or boardState[2][2] == "T") and (boardState[3][3] == winningSymbol or boardState[3][3] == "T"):
        return True

    if (boardState[0][3] == winningSymbol or boardState[0][3] == "T") and (boardState[1][2] == winningSymbol or boardState[1][2] == "T") and (boardState[2][1] == winningSymbol or boardState[2][1] == "T") and (boardState[3][0] == winningSymbol or boardState[3][0] == "T"):
        return True

def hasEmptySpaces(boardState):
    for row in range(len(boardState)):
        for column in range(len(boardState)):
            if boardState[row][column] == ".":
                return True
    return False

def ticTacToeTomek(boardState):
    if hasWon(boardState, "X"):
        return "X won"
    elif hasWon(boardState, "O"):
        return "O won"
    elif hasEmptySpaces(boardState):
        return "Game has not completed"
    return "Draw"

def run(inputFile, outputFile = "output.txt"):

    reader = open(inputFile)
    writer = open(outputFile, 'w')
    caseCounter = 1
    boardState = []
    
    for line in reader.readlines()[1:]:

        line = line.strip()
        
        if line == "":
            boardState = []
            continue

        boardRow = []

        for token in line:
            boardRow.append(token)

        boardState.append(boardRow)

        if len(boardState) == 4:
            print boardState
            writer.write("Case #" + str(caseCounter) + ": " + ticTacToeTomek(boardState) + "\n")
            caseCounter = caseCounter + 1
            
    print "Program completed successfully. Look at " + outputFile + " for output"
        
    
