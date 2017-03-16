import sys
import operator

inFile = open(sys.argv[1], 'r')

numCases = int(inFile.readline())
for case in range(1, numCases + 1):
    soFar, totalChars = map(int, inFile.readline().split())
    probsRight = map(float, inFile.readline().split())
    probsWrong = [1 - x for x in probsRight]
    numStrokes = totalChars + 2

    probRightSoFar = 1.0
    for error in range(soFar + 1):
        backspace = soFar - error
        rightChars = 2 * backspace + totalChars - soFar + 1
        wrongChars = rightChars + totalChars + 1
        strokes = probRightSoFar * rightChars + (1 - probRightSoFar) * wrongChars
        numStrokes = min(numStrokes, strokes)
        if error < soFar:
            probRightSoFar *= probsRight[error]
        #print  backspace, strokes, probEnough, rightChars, wrongChars

    print 'Case #%d: %.6f' % (case, numStrokes)
