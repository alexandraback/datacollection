import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            return [tuple(map(int, f.readline().split())) for l in xrange(lineCount)]

# Guess r=1
def solve1(caseVal):
    r, c, w = caseVal
    if w == c:
        return w
    if w <= c // 2:
        return 1 + solve((r, c // 2, w))
    else:
        return w

# Guess r=1
def solve2(caseVal):
    r, c, w = caseVal
    if w == c:
        return w
    if w <= c // 2:
        return min(1 + solve((r, c // 2, w)), 1+solve((r, (c - 1) // 2, w)))
    else:
        return w

# Guess r=1
def solve(caseVal):
    r, c, w = caseVal
    if c % w == 0:
        return c // w + w - 1
    return c // w + w

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
