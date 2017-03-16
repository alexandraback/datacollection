import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            lineCount = int(f.readline())
            return [int(f.readline()) for l in xrange(lineCount)]

def reverse(n):
    return int(str(n)[::-1])

tab = [-1] * 10000000

def solve(caseVal):
    #print 'try:', caseVal
    if caseVal == 1:
        return 1
    elif tab[caseVal] > 0:
        return tab[caseVal]
    else:
        r = reverse(caseVal)
        if r < caseVal and len(str(r)) == len(str(caseVal)):
            tmp = min(solve(caseVal-1), solve(r))+1
            #print caseVal, tmp
            if tmp < tab[caseVal] or tab[caseVal] < 0:
                tab[caseVal] = tmp
            return tmp
        else:
            tmp = solve(caseVal-1)+1
            #print caseVal, tmp
            if tmp < tab[caseVal] or tab[caseVal] < 0:
                tab[caseVal] = tmp
            return tmp

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
