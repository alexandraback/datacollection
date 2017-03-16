import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            return [map(int, f.readline().split()) for i in range(lineCount)]

def solveNaive(caseVal):
    (x, rows, cols) = caseVal
    assert(x > 0 and rows > 0 and cols > 0)
    if (rows*cols) % x != 0:
        return False
    if x in [1, 2]:
        return True
    elif x == 3:
        return min(rows, cols) >= 2 and max(rows, cols) >= 3
    elif x == 4:
        return min(rows, cols) >= 3 and max(rows, cols) >= 4
    elif x == 5:
        return min(rows, cols) >= 3 and max(rows, cols) >= 5
    elif x == 6:
        return min(rows, cols) >= 4 and max(rows, cols) >= 6
    elif x >= 7: # with x >= 7 there is tile with hole so Richard can cheat with it
        return False
    return False

def solve(caseVal):
    return solveNaive(caseVal)

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %s' % (caseId+1, 'GABRIEL' if result else 'RICHARD')


if __name__ == '__main__':
    for caseId, caseVal in enumerate(getInputs()):
        writeOutput(caseId, solve(caseVal))

