"""
Google Code Jam
Online Qualifying Round

Problem C - Minesweeper Master

Given an RxC size board, and a number
of mines M, find a board configuration
which can be solved in one click.

If it is possible, output the board
configuration (including the click spot)

If it is impossible, output "Impossible!"
"""
def main():
    INFILENAME = 'C-large.in'
    OUTFILENAME = 'C-large.out'
    
    infile = open(INFILENAME)
    cases = int(infile.readline())
    
    outfile = open(OUTFILENAME, 'w')
    
    for case in range(1, cases+1):
        
        # Get the board
        rows, cols, mines = (int(x) for x in infile.readline().split())
        realrows, realcols, realmines = rows, cols, mines # because we modify them when we do reduction
        
        # Delete rows if possible
        while mines - cols > rows+cols-1:
            mines -= cols
            rows -= 1
        
        # Delete columns if possible
        while mines - rows > rows+cols-1:
            mines -= rows
            cols -= 1
        
        # Fill the board optimally with mines
        possible, board = fillBoard(rows, cols, mines)
        
        # Enlarge the board again
        board = enlargeBoard(board, realrows, realcols, rows, cols)
        
        # Print the results
        outfile.write("Case #{}:\n".format(case))
        print("Case #{}: {}x{}, {} mines".format(case, realrows, realcols, realmines))
        printBoard(board)
        print('Possible\n\n' if possible else 'Impossible\n\n')
        if possible:
            writeBoard(board, outfile)
        else:
            outfile.write("Impossible\n")    

def fillBoard(rows, cols, mines):
    """
    Strategy: fill board in L formations
    """
    # Try it rows first
    print('Trying rows L')
    board = [['.']*cols for i in range(rows)]
    possible, board = rowsFirstL(board, rows, cols, mines)
    
    # If it didn't work, try it cols first
    if not possible:
        print('Trying cols L')
        board = [['.']*cols for i in range(rows)]
        possible, board = colsFirstL(board, rows, cols, mines)
    
    if not possible:
        print('Trying straight up rows first')
        possible, board = rowsFirst(rows, cols, mines)
    
    if not possible:
        print('Trying straight up cols first')
        possible, board = colsFirst(rows, cols, mines)
        
    
    return possible, board

def rowsFirstL(board, rows, cols, mines):
    # Innoncent until proven guilty
    possible = True
    
    totalmines = mines
    
    smaller = min(rows,cols)
    for pos in range(smaller-2):
        if mines <= 0:
            break
        mines, board = tryFillRowsFirst(board, pos, pos, rows, cols, mines)
    
    # If mines are remaining after filling all the L's,
    # then it is POSSIBLE if the remaining mines can
    # fit in the edges properly
    if mines > 0:
        remainingspots = rows*cols - (totalmines - mines)
        if remainingspots % 2 == 0 and mines % 2 == 0:
            possible = True
            # Fill the bottom two rows as much as possible
            for col in range(0, cols-2):
                if mines > 0:
                    if rows >= 2:
                        if board[rows-2][col] != '*':
                            board[rows-2][col] = '*'
                            mines -= 1
                    if board[rows-1][col] != '*':
                        board[rows-1][col] = '*'
                        mines -= 1
            # Fill the bottom right columns as much as possible
            for row in range(0, rows-2):
                if mines > 0:
                    if cols >= 2:
                        if board[row][cols-2] != '*':
                            board[row][cols-2] = '*'
                            mines -= 1
                    if board[row][cols-1] != '*':
                        board[row][cols-1] = '*'
                        mines -= 1
        else:
            possible = False

    # If there is only one non-mine spot, then it is possible
    if rows*cols - totalmines == 1:
        board = [['*']*cols for i in range(rows)]
        possible = True
    
    if rows*cols - totalmines in {0, 2, 3}:
        possible = False

    # If this is a 1xC or Rx1 board, it is ALWAYS
    # possible.
    if rows == 1 or cols == 1:
        possible = True
        if rows == 1:
            for col in range(cols):
                if mines < 1:
                    break
                board[0][col] = '*'
                mines -= 1
        elif cols == 1:
            for row in range(rows):
                if mines < 1:
                    break
                board[row][0] = '*'
                mines -= 1
    
    # Put the 'click' on the board, yo
    board[rows-1][cols-1] = 'c'
    
    return possible, board

def colsFirstL(board, rows, cols, mines):
    # Innocent until proven guilty
    possible = True
    
    totalmines = mines
    
    smaller = min(rows,cols)
    for pos in range(smaller-2):
        if mines <= 0:
            break
        mines, board = tryFillColsFirst(board, pos, pos, rows, cols, mines)
    
    # If mines are remaining after filling all the L's,
    # then it is POSSIBLE if the remaining mines can
    # fit in the edges properly
    if mines > 0:
        remainingspots = rows*cols - (totalmines - mines)
        if remainingspots % 2 == 0 and mines % 2 == 0:
            possible = True
            # Fill the bottom two rows as much as possible
            for col in range(0, cols-2):
                if mines > 0:
                    if rows >= 2:
                        if board[rows-2][col] != '*':
                            board[rows-2][col] = '*'
                            mines -= 1
                    if board[rows-1][col] != '*':
                        board[rows-1][col] = '*'
                        mines -= 1
            # Fill the bottom right columns as much as possible
            for row in range(0, rows-2):
                if mines > 0:
                    if cols >= 2:
                        if board[row][cols-2] != '*':
                            board[row][cols-2] = '*'
                            mines -= 1
                    if board[row][cols-1] != '*':
                        board[row][cols-1] = '*'
                        mines -= 1
        else:
            possible = False

    # If there is only one non-mine spot, then it is possible
    if rows*cols - totalmines == 1:
        board = [['*']*cols for i in range(rows)]
        possible = True
    
    if rows*cols - totalmines in {0, 2, 3}:
        possible = False

    # If this is a 1xC or Rx1 board, it is ALWAYS
    # possible.
    if rows == 1 or cols == 1:
        possible = True
        if rows == 1:
            for col in range(cols):
                if mines < 1:
                    break
                board[0][col] = '*'
                mines -= 1
        elif cols == 1:
            for row in range(rows):
                if mines < 1:
                    break
                board[row][0] = '*'
                mines -= 1
    
    # Put the 'click' on the board, yo
    board[rows-1][cols-1] = 'c'
    
    return possible, board

def tryFillRowsFirst(board, lrow, lcol, rows, cols, mines):
    """
    Tries to fill the board starting at (rowstart, colstart) in
    a formation like
    ----------
    |
    |
    |
    |
    Where the last two cols and rows get filled only if the remaining
    mines have at least 2 (no lone cols or rows)
    """
    # Fill the column down
    for row in range(lrow, rows-2):
        if mines > 0:
            board[row][lcol] = '*'
            mines -= 1
            
    # Try to fill the last two cells in the column
    if mines >= 2:
        board[rows-2][lcol] = '*'
        board[rows-1][lcol] = '*'
        mines -= 2
    
    # Fill the row across
    for col in range(lcol+1, cols-2):
        if mines > 0:
            board[lrow][col] = '*'
            mines -= 1
    
    # Try to fill the last two cells in the row
    if mines >= 2:
        board[lrow][cols-2] = '*'
        board[lrow][cols-1] = '*'
        mines -= 2
    
    return (mines, board)

def tryFillColsFirst(board, lrow, lcol, rows, cols, mines):
    """
    Tries to fill the board starting at (rowstart, colstart) in
    a formation like
    ----------
    |
    |
    |
    |
    Where the last two cols and rows get filled only if the remaining
    mines have at least 2 (no lone cols or rows)
    """    
    # Fill the row across
    for col in range(lcol, cols-2):
        if mines > 0:
            board[lrow][col] = '*'
            mines -= 1
    
    # Try to fill the last two cells in the row
    if mines >= 2:
        board[lrow][cols-2] = '*'
        board[lrow][cols-1] = '*'
        mines -= 2
    
    # Fill the column down
    for row in range(lrow+1, rows-2):
        if mines > 0:
            board[row][lcol] = '*'
            mines -= 1
            
    # Try to fill the last two cells in the column
    if mines >= 2:
        board[rows-2][lcol] = '*'
        board[rows-1][lcol] = '*'
        mines -= 2
    
    return (mines, board)

def rowsFirst(rows, cols, mines):
    # Initialize board to empty cells
    board = [['.']*cols for i in range(rows)]
    # Innocent until proven guilty
    possible = True

    totalmines = mines

    # Fill n-2 rows in order without leaving lone cols
    if cols > 1:
        for row in range(rows-2):
            if mines < 1:
                break
            for col in range(cols-2):
                if mines <= 0:
                    break
                board[row][col] = '*'
                mines -= 1
            if mines >= 2:
                # Fill the last two
                board[row][cols-2] = '*'
                board[row][cols-1] = '*'
                mines -= 2
    
    # Fill bottom 2 rows without leaving an empty row
    if rows > 1:
        for col in range(cols-2):
            if mines < 2:
                if mines == 1:
                    possible = False
                break
            board[rows-2][col] = '*'
            board[rows-1][col] = '*'
            mines -= 2
    
    if mines > 0:
        # If this is a 1xC or Rx1 board, it is ALWAYS
        # possible.
        if rows == 1 or cols == 1:
            possible = True
            if rows == 1:
                for col in range(cols):
                    if mines < 1:
                        break
                    board[0][col] = '*'
                    mines -= 1
            elif cols == 1:
                for row in range(rows):
                    if mines < 1:
                        break
                    board[row][0] = '*'
                    mines -= 1
        else:
            # There are the 4 bottom-right squares left,
            # and since there are mines remaining, it's an
            # impossible board
            possible = False
            
            # Fill them in a bullshit way
            colstart = max(cols-2, 0)
            rowstart = max(rows-2, 0)
            for row in range(rowstart, rows):
                for col in range(colstart, cols):
                    if mines < 1:
                        break
                    board[row][col] = '*'
                    mines -= 1
    
    # If there is only one non-mine spot, then it is possible
    if rows*cols - totalmines == 1:
        possible = True
    
    # Put the 'click' on the board, yo
    board[rows-1][cols-1] = 'c'
    
    return possible, board

def colsFirst(rows, cols, mines):
    # Initialize board to empty cells
    board = [['.']*cols for i in range(rows)]
    # Innocent until proven guilty
    possible = True

    totalmines = mines

    # Fill n-2 cols in order without leaving lone rows
    if rows > 1:
        for col in range(cols-2):
            if mines < 1:
                break
            for row in range(rows-2):
                if mines <= 0:
                    break
                board[row][col] = '*'
                mines -= 1
            if mines >= 2:
                # Fill the last two
                board[rows-2][col] = '*'
                board[rows-1][col] = '*'
                mines -= 2
    
    # Fill rightmost 2 cols without leaving an empty col
    if cols > 1:
        for row in range(rows-2):
            if mines < 2:
                if mines == 1:
                    possible = False
                break
            board[row][cols-2] = '*'
            board[row][cols-1] = '*'
            mines -= 2
    
    if mines > 0:
        # If this is a 1xC or Rx1 board, it is ALWAYS
        # possible.
        if rows == 1 or cols == 1:
            possible = True
            if rows == 1:
                for col in range(cols):
                    if mines < 1:
                        break
                    board[0][col] = '*'
                    mines -= 1
            elif cols == 1:
                for row in range(rows):
                    if mines < 1:
                        break
                    board[row][0] = '*'
                    mines -= 1
        else:
            # There are the 4 bottom-right squares left,
            # and since there are mines remaining, it's an
            # impossible board
            possible = False
            
            # Fill them in a bullshit way
            colstart = max(cols-2, 0)
            rowstart = max(rows-2, 0)
            for row in range(rowstart, rows):
                for col in range(colstart, cols):
                    if mines < 1:
                        break
                    board[row][col] = '*'
                    mines -= 1
    
    # If there is only one non-mine spot, then it is possible
    if rows*cols - totalmines == 1:
        possible = True
    
    # Put the 'click' on the board, yo
    board[rows-1][cols-1] = 'c'
    
    return possible, board
    

def enlargeBoard(board, realrows, realcols, rows, cols):
    realboard = [['*']*realcols for i in range(realrows)]
    
    rowdif = realrows-rows
    coldif = realcols-cols
    for row in range(rows):
        for col in range(cols):
            realboard[row+rowdif][col+coldif] = board[row][col]
    
    return realboard

def printBoard(board):
    for row in board:
        rowstr = ''
        for cell in row:
            rowstr += cell
        print(rowstr)

def writeBoard(board, outfile):
    for row in board:
        rowstr = ''
        for cell in row:
            rowstr += cell
        outfile.write('{}\n'.format(rowstr))
    
main()