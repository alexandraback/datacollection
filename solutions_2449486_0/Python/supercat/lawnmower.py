import re

def parseInput(filePath):
    f = open(filePath, 'r')
    numRE = re.compile('\d+')
    
    # Parse number of test cases
    line = f.readline()
    nTestCases = int(line)
    
    # Initialise array for data
    words = [[] for i in range(nTestCases)]
    
    # Parse each test case
    nRows = [0 for i in range(nTestCases)]
    nCols = [0 for i in range(nTestCases)]
    heights = [[] for i in range(nTestCases)]
    for i in range(nTestCases):    
        # Parse size of test case
        line = f.readline()
        sizeStr = numRE.findall(line)
        nRows[i] = int(sizeStr[0])
        nCols[i] = int(sizeStr[1])
        
        # Parse heights
        h = [[0 for k in range(nCols[i])] for j in range(nRows[i])]
        for j in range(nRows[i]):
            line = f.readline()
            numStr = numRE.findall(line)
            h[j] = [int(numStr[k]) for k in range(nCols[i])]
        heights[i] = h
    
    # Return test case data
    return (nTestCases, nRows, nCols, heights)
    
    
    
def solve(nTestCases, nRows, nCols, heights):
    result = [True for i in range(nTestCases)]
    
    print nTestCases
    
    for i in range(nTestCases):
        h = heights[i]
        maxRow = [max(h[j]) for j in range(nRows[i])]
        maxCol = [max([h[j][k] for j in range(nRows[i])]) for k in range(nCols[i])]
        
        print range(nTestCases)
        print 'Test case ', i
        print 'maxRow: ', maxRow
        print 'maxCol: ', maxCol
        
        for j in range(nRows[i]):
            for k in range(nCols[i]):
                if h[j][k] != maxRow[j] and h[j][k] != maxCol[k]:
                    result[i] = False
                    break
                    
            if result[i] == False:
                break
        
    return result
    
    
    
def printResult(result, outFilePath):
    f = open(outFilePath, 'w')
    for i in range(len(result)):
        s = 'Case #%d:' % (i+1)
        if result[i]:
            print >> f, s, 'YES'
        else:
            print >> f, s, 'NO'
    f.close()
    
    
filePath = 'B-small-attempt1.in'
outFilePath = 'B-small-attempt1.out'
(nTestCases, nRows, nCols, heights) = parseInput(filePath)
result = solve(nTestCases, nRows, nCols, heights)
printResult(result, outFilePath)