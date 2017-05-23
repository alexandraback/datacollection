import copy

def main():
    fileName = "C-small-attempt3.in"
    file = open(fileName)

    # Loop for the number of tests there are.
    for case in range(1, int(file.readline()) + 1):
        # Read in the values.
        values = file.readline().split()
        row = int(values[0])
        col = int(values[1])
        mines = int(values[2])

        # Initialize the array with mines and find the number of empty squares.
        array = [["*" for _ in range(col)] for _ in range(row)]
        cells = row * col - mines
        
        # Fill the array with clear spaces in a square format.
        tempCells = cells
        canAddH = True
        canAddV = True
        botValue = 0
        tempRow = 0
        tempCol = 0
        
        while(tempCells):
            array[tempRow][tempCol] = "."
            tempCells -= 1

            # If you can still add both horizontally and vertically,
            if (canAddH and canAddV):
                # If at a diagonal,
                if (tempRow == tempCol):
                    # Update the botValue
                    botValue += 1
                    canAddH = botValue < len(array)
                    canAddV = botValue < len(array[0])

                    # If canAddV, then continue as normal.
                    if (canAddV):
                        tempCol = botValue
                        tempRow = 0
                    # Else, move to the next row.
                    elif (canAddH):
                        tempRow = botValue
                        tempCol = 0
                # If at top right corner,
                elif (tempRow < tempCol):
                    if ((tempRow == 0 and tempCol != 1) \
                        or (tempCells == 1 and tempRow + 1 != tempCol)):
                        tempRow += 1
                    else:
                        if (tempRow == 1):
                            tempRow -= 1
                        tempRow, tempCol = tempCol, tempRow
                # If at bottom left corner,
                elif (tempRow > tempCol):
                    if ((tempCol == 0 and tempRow != 1) \
                        or (tempCells == 1 and tempCol + 1 != tempRow)):
                        tempCol += 1
                    else:
                        tempRow, tempCol = tempCol + 1, tempRow
                # If this is the corner and there are two more cells, do not fill.
                if (tempRow == tempCol and tempCells == 2):
                    tempValue = tempRow
                    
                    # Update the botValue
                    botValue += 1
                    canAddH = botValue < len(array)
                    canAddV = botValue < len(array[0])

                    # If canAddV, then continue as normal.
                    if (canAddV and row > 2):
                        tempCol = botValue
                        tempRow = 0
                    # Else, move to the next row.
                    elif (canAddH and col > 2):
                        tempRow = botValue
                        tempCol = 0
                    # Else, don't do this bullshit.
                    else:
                        # Reset botValue.
                        botValue -= 1
                        canAddH = botValue < len(array)
                        canAddV = botValue < len(array[0])

                        # Fix it back to the old value.
                        tempRow = tempValue
                        tempCol = tempValue
            
            # Else, if you can only add horizontally,
            elif (canAddH):
                # If not at the last column, keep filling normally to the right,
                if (tempCol + 1 < len(array[0])):
                    tempCol += 1
                # Else, keep filling the next row.
                else:
                    botValue += 1
                    tempRow = botValue
                    tempCol = 0
                # If this is the corner piece and there are two more cells, do not fill.
                if (tempCol + 1 == len(array[0]) and tempCells == 2 and col > 2):
                    botValue += 1
                    tempRow = botValue
                    tempCol = 0
                    
            # Else if you can only add vertically,
            elif (canAddV):
                # If not at the last row, keep filling normally to the bottom,
                if (tempRow + 1 < len(array)):
                    tempRow += 1
                # Else, keep filling the next column.
                else:
                    botValue += 1
                    tempRow = 0
                    tempCol = botValue
                # If this is the corner piece and there are two more cells, do not fill.
                if (tempRow + 1 == len(array) and tempCells == 2 and row > 2):
                    botValue += 1
                    tempCol = botValue
                    tempRow = 0
                    
    # Click the topmost position and check neighbors.
        tempRow = 0;
        tempCol = 0;
        array[tempRow][tempCol] = "c"
        tempArray = copy.deepcopy(array)
        backtrackingNeighbors(tempRow, tempCol, tempArray)

        # Check if there was an untouched cell.
        print("Case #" + str(case) + ":")
        isImpossible = False
        for r in range(len(tempArray)):
            if (isImpossible):
                break
            for c in range(len(tempArray[r])):
                if (tempArray[r][c] == "."):
                    isImpossible = True
                    print("Impossible")
                    break;

        if (not isImpossible):
            for r in range(len(array)):
                for c in range(len(array[r])):
                    print(array[r][c],end="")
                print()

def backtrackingNeighbors(row, col, array):
    # Base case is check out of bounds.
    if (outOfBounds(row, col, array)):
        return
    # Base case is having a neighbor as a mine.
    elif (checkNeighbors(row, col, array) == False):
        array[row][col] = "#"
        return
    else:
        array[row][col] = "0"
        backtrackingNeighbors(row  , col+1, array)
        backtrackingNeighbors(row+1, col  , array)
        backtrackingNeighbors(row+1, col+1, array)

def outOfBounds(row, col, array):
    # Check self.
    if (row < 0 or row >= len(array) or col < 0 or col >= len(array[row])):
        return True

def checkNeighbors(row, col, array):
    # Check top left.
    if (row - 1 >= 0 and col - 1 >= 0 and array[row-1][col-1] == "*"):
        return False
        
    # Check top middle.
    if (row - 1 >= 0 and array[row-1][col] == "*"):
        return False

    # Check top right.
    if (row - 1 >= 0 and col + 1 < len(array[row-1]) and array[row-1][col+1] == "*"):
        return False

    # Check middle left.
    if (col - 1 >= 0 and array[row][col-1] == "*"):
        return False

    # Check middle right.
    if (col + 1 < len(array[row]) and array[row][col+1] == "*"):
        return False

    # Check bottom left.
    if (row + 1 < len(array) and col - 1 >= 0 and array[row+1][col-1] == "*"):
        return False

    # Check bottom middle.
    if (row + 1 < len(array) and array[row+1][col] == "*"):
        return False

    # Check bottom right.
    if (row + 1 < len(array) and col + 1 < len(array[row+1]) and array[row+1][col+1] == "*"):
        return False
    

if __name__ == "__main__":
    main()
