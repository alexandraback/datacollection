import sys

def solve(polyominoSize, bigDim, smallDim):
    # If the polyomino size X is at least 7, Richard can always win by choosing
    # a polyomino with an internal "hole".
    if polyominoSize >= 7:
        return True
    
    # If the board's dimensions are both smaller than X, Richard can always win
    # by choosing the long polyomino.
    if bigDim < polyominoSize:
        return True
    
    # If the number of spaces is not a multiple of X, Richard can win by
    # choosing any polyomino.
    if (bigDim * smallDim) % polyominoSize != 0:
        return True
    
#     # If the sum of dimensions is less than X, it will always be possible for
#     # Richard to choose a polyomino that cannot fit in the board at all.
#     if bigDim + smallDim < polyominoSize:
#         return True
    
    # If one of the dimensions is small enough, it will be possible for Richard
    # to choose a polyomino that is too large to fit anywhere regardless of
    # orientation.
    if 2 * smallDim < polyominoSize:
        return True
    
    # Otherwise, if X is 1 or 2, there is only one possible polyomino and
    # Gabriel can always win. If X is 3 and the above checks fail, Gabriel can
    # always win even though Richard has two choices of polyomino.
    if polyominoSize <= 3:
        return False
    
    # Experimentation with the cases 4 <= X <= 6 reveals that, when the above
    # conditions do not hold, there are only a few cases where Richard wins.
    # They are as follows:
    # - X = 4 and the board is 2 by 4.
    # - X = 5 and the board is 3 by 5.
    # - X = 6 and the board is 3 by 6.
    return (polyominoSize == 4 and bigDim == 4 and smallDim == 2) \
        or (polyominoSize == 5 and bigDim == 5 and smallDim == 3) \
        or (polyominoSize == 6 and bigDim == 6 and smallDim == 3)

if __name__ == '__main__':
#     inFile = sys.stdin
    # Read input from a file to work around the lack of support for using a file
    # as STDIN in Eclipse.
    inFile = open('input/D-small-attempt1.in')
    
    numCases = int(inFile.readline().rstrip())
    for case in range(1, numCases+1):
        inTokens = inFile.readline().split()
        polyominoSize = int(inTokens[0])
        numRows = int(inTokens[1])
        numCols = int(inTokens[2])
        
        result = solve(polyominoSize, max(numRows, numCols),
            min(numRows, numCols))
        
        # Print result.
        resultStr = 'RICHARD' if result else 'GABRIEL'
        print('Case #%s: %s' % (case, resultStr))
    
    inFile.close()