import sys

def solve(levelsList):
    initialNumPeople = sum(levelsList)
    numStanding = levelsList[0]
    nextLevel = 1
    numAdded = 0
    
    while numStanding < initialNumPeople + numAdded:
        while numStanding >= nextLevel and nextLevel < len(levelsList):
            numStanding += levelsList[nextLevel]
            nextLevel += 1
        
        if numStanding < initialNumPeople + numAdded:
            numAdded += 1
            numStanding += 1
    
    return numAdded

if __name__ == '__main__':
#     inFile = sys.stdin
    # Read input from a file to work around the lack of support for using a file
    # as STDIN in Eclipse.
    inFile = open('../input/A-small-attempt0.in')
    
    numCases = int(inFile.readline())
    for case in range(1, numCases+1):
        inTokens = inFile.readline().split()
        numLevels = int(inTokens[0])
        levelsList = [int(c) for c in inTokens[1]]
        
        result = solve(levelsList)
        
        # Print result.
        print('Case #%s: %s' % (case, result))
    
    inFile.close()