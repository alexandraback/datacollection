import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            return [map(int, f.readline().split()) for i in range(lineCount)]

def solveNaive(caseVal):
    (x, rows, cols) = caseVal
    # |oo |
    # | oo|
    # => Doesn't fill all rectangles
    # |ooo|    |o  |
    # |o o| or |ooo|
    #          |  o|
    # => Doesn't fill all rectangles
    # => with x > 3, there is a tile that cannot tile a rectangular region
    assert(x > 0 and rows > 0 and cols > 0)
    if (rows*cols) % x != 0:
        return False
    if x in [1, 2]:
        return True
    elif x == 3:
        return rows >= 2 and cols >= 2
    else:
        return min(rows, cols) >= 3 and max(rows, cols) >= 4

def solve(caseVal):
    return solveNaive(caseVal)

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %s' % (caseId+1, 'GABRIEL' if result else 'RICHARD')


if __name__ == '__main__':
    for caseId, caseVal in enumerate(getInputs()):
        writeOutput(caseId, solve(caseVal))

