import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            return [tuple(map(int, f.readline().split())) for l in xrange(lineCount)]

# Guess r=1
def solveSimple(caseVal):
    r, c, w = caseVal
    if c % w == 0:
        return c // w + w - 1
    return c // w + w

def solve(caseVal):
    r, c, w = caseVal
    if c % w == 0:
        return c // w + w - 1     +     (r - 1) * (c // w)
    return c // w + w     +     (r - 1) * (c // w)

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
