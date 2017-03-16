import sys
from itertools import *


def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            pbs = []
            for i in range(lineCount):
                c, d, v = tuple(map(int, f.readline().split()))
                dl = map(int, f.readline().split())
                pbs.append((c, dl, v))
            return pbs

# Guess c=1
def solve(caseVal):
    c, d, v = caseVal
    assert(c == 1)
    addedCount = 0
    for i in range(v+1):
        toAdd = i
        for j in product([0, 1], repeat=len(d)):
            if i == sum(d[k] * j[k] for k in range(len(d))):
                toAdd = None
                break
        if toAdd:
            #print 'toAdd: ', toAdd
            d.append(toAdd)
            addedCount += 1
        d = sorted(d)
    return addedCount

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
