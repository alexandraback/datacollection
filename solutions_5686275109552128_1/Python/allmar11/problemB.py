import math
import sys

MAX_LEVEL = 10000

def solve(numCakesList):
    # Note: numCakesList must be pre-sorted in descending order.
    bestTime = -1
    for level in range(MAX_LEVEL, 0, -1):
        pausesRequired = 0
        for cakeStack in numCakesList:
            if cakeStack <= level:
                break;
            else:
                pausesRequired += int(math.ceil((cakeStack - level) / level))
        time = pausesRequired + level
        if bestTime == -1 or time < bestTime:
            bestTime = time
    
    return bestTime
    

if __name__ == '__main__':
#     inFile = sys.stdin
    # Read input from a file to work around the lack of support for using a file
    # as STDIN in Eclipse.
    inFile = open('../input/B-large.in')
    
    numCases = int(inFile.readline())
    for case in range(1, numCases+1):
        numNonempty = int(inFile.readline())
        numCakesList = [int(token) for token in inFile.readline().split()]
        numCakesList.sort(reverse=True)
        
        result = solve(numCakesList)
        
        # Print result.
        print('Case #%s: %s' % (case, result))
    
    inFile.close()