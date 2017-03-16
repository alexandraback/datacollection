#4x4 board
#4 in a row to win, diagonally or row/column
#T symbol counts as either X or O
#. = empty square

#If no one won, output draw if all filled, or not completed if any empty

#4 possible rows
#4 possible columns
#2 possible diagonals

def calculateMultiple (games):
    output = ""
    
    currentGame = ""
    currentPosition = 1
    currentRow = 0
    first = True
    for line in games.split("\n"):
        if len(line) <= 1 or first:
            first = False
            continue

        currentGame += line
        currentGame += "\n"
        currentRow += 1
        
        if currentRow == 4:
            output += "Case #{0}: {1}\n".format(currentPosition, calculateEnding(currentGame))
            
            currentGame = ""
            currentRow = 0
            currentPosition += 1

    print(output)
    with open("OUTPUT.txt", "w") as file:
        file.write(output)

        
    
def calculateSequence (sequence):
    #0 = None
    #1 = X Won -- winning until completed
    #2 = 0 Won -- winning until completed
    current = 0
    
    for position in sequence:
        if position == "X":
            if current == 2:
                current = 0
                break
            
            current = 1
            continue
        
        if position == "O":
            if current == 1:
                current = 0
                break
            
            current = 2
            continue

        if position == ".":
            current = 0
            break

    if current == 0:
        return None

    if current == 1:
        return "X won"

    if current == 2:
        return "O won"
        
    
def calculateEnding (game):
    board = [[None, None, None, None], [None, None, None, None], [None, None, None, None], [None, None, None, None]]
    x = 0
    y = 0
    filled = True
    for position in game:
        if position == "\n":
            x = 0
            y += 1
            continue

        if position == ".":
            filled = False
        
        board[y][x] = position;
        
        x += 1
    
    for y in range(4):
        row = board[y]
        result = calculateSequence(row)
        if result != None:
            return result

    for x in range(4):
        column = []
        for y in range(4):
            column += board[y][x]

        result = calculateSequence(column)
        if result != None:
            return result

    diagonal1 = [board[0][0], board[1][1], board[2][2], board[3][3]]
    diagonal2 = [board[0][3], board[1][2], board[2][1], board[3][0]]
    
    diagonals = [diagonal1, diagonal2]
    
    for diagonal in diagonals:  
        result = calculateSequence(diagonal)
        if result != None:
            return result

    if filled:
        return "Draw"

    else:
        return "Game has not completed"
    
