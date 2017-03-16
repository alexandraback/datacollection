import sys

def printMat(mat):
    ''' Print a matrix. '''
    for row in mat:
        print(''.join(row))

def mine():
    '''
    Solve one minesweeper test case.
    Idea: Place blank spaces instead of mines.  Put the blanks beginning at
    (0, 0); add a row then a column of blanks at a time.
    Always click at (0, 0).
    On a new row/col we must add at least 2 blanks at a time.
    '''

    rows, cols, mines = map(int, sys.stdin.readline().split())
    matSize = { 'rows': rows, 'cols': cols }

    minSize = min(rows, cols)

    # Number of blank spaces to put
    blanks = rows * cols - mines

    if (1 < blanks < 4) and (rows != 1 and cols != 1):
        # We need a 1xC or Rx1 matrix for this to work with 2 or 3 blanks.
        # This case would add complexity down below, so we deal here
        print('Impossible')
        return

    # Create a 2d matrix of all mines, [rows][cols] large
    mat = [['*']*cols for _ in range(rows)]

    # Always click in corner
    mat[0][0] = 'c'
    blanks -= 1
    # Take care of 1 blank only, to avoid complications
    if blanks == 0:
        printMat(mat)
        return
    # Size of the blanks we have put down
    blankSize = { 'rows': 1, 'cols': 1 }

    # Placers for convenience
    def placeRow(row, i, fill='.'): mat[row][i] = fill
    def placeCol(col, i, fill='.'): mat[i][col] = fill
    placers = { 'rows': placeRow, 'cols': placeCol }

    while True:
        # Try to place a row then a column (order of this doesn't matter)
        for rc in ('rows', 'cols'):
            if blankSize[rc] >= matSize[rc]: continue

            other = 'rows' if rc == 'cols' else 'cols'

            if blankSize[other] > 1 and blanks < 2:
                # Not 1-wide but less than 2 blanks on a new row/col
                print('Impossible')
                return

            # Placer function (row or col)
            placer = placers[rc]
            placed = min(blankSize[other], blanks)

            # Place all blanks in mat
            for i in range(0, placed): placer(blankSize[rc], i)

            if placed == blankSize[other]:
                # We placed a whole row/col
                blankSize[rc] += 1

            blanks -= placed
            if blanks == 0:
                # Success if no more blanks
                printMat(mat)
                return
            if blanks == 1 and minSize >= 3 and placed >= 3:
                # Danger of failing uselessly here
                # Last blank should have actually been a mine
                placer(blankSize[rc]-1, blankSize[other]-1, fill='*')
                blanks += 1

def main(n):
    ''' Read and perform n test cases. '''

    for i in range(1, n+1):
        print('Case #{}:'.format(i))
        mine()

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    main(n)
