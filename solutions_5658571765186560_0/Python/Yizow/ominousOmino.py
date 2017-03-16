import sys

def main():
    inputFileName = sys.argv[1]
    outputFileName = sys.argv[2]
    with open(inputFileName, 'r') as inputFile:
        with open(outputFileName, 'w') as outputFile:
            numTestCases = int(inputFile.readline())
            for testNum in range(numTestCases):
                if testNum > 0:
                    outputFile.write("\n")
                X, R, C = inputFile.readline().split()
                X, R, C = int(X), int(R), int(C)
                if R < C: 
                    R, C = C, R
                possible = perfectFill(X, R, C) and maxX(X) and fitsBounds(X, R, C) and trappedCorner(X, C)
                if possible == True:
                    winner = 'GABRIEL'
                else:
                    winner = 'RICHARD'
                if X == 1: 
                    winner = 'GABRIEL'
                outputFile.write("Case #%d: %s" % (testNum+1, winner))

# Boolean denotes if problem is solvable
# True denotes Gabriel wins
# False means Richard wins 
def perfectFill(X, R, C):
    return (R*C)%X == 0

# If X >= 7, richard chooses a tetromino with a hole
def maxX(X):
    return X < 7

# R > C is enforced
def fitsBounds(X, R, C):
    for i in range(X/2):
        shortSide = i+1 + 1
        longSide = X - shortSide + 1
        if longSide < shortSide:
            shortSide, longSide = longSide, shortSide
        if longSide > R or shortSide > C:
            return False
    return True

# A corner can be fenced off
def trappedCorner(X, C):
    if C == 1: return True
    return X/2<C or X%C > 0

main()