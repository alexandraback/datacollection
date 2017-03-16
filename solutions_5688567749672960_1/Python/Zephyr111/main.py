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

def solveSlow(caseVal):
    #print 'try:', caseVal
    if caseVal == 1:
        return 1
    elif tab[caseVal] > 0:
        return tab[caseVal]
    else:
        r = reverse(caseVal)
        if r < caseVal and len(str(r)) == len(str(caseVal)):
            tmp = min(solveSlow(caseVal-1), solveSlow(r))+1
            #print caseVal, tmp
            if tmp < tab[caseVal] or tab[caseVal] < 0:
                tab[caseVal] = tmp
            return tmp
        else:
            tmp = solveSlow(caseVal-1)+1
            #print caseVal, tmp
            if tmp < tab[caseVal] or tab[caseVal] < 0:
                tab[caseVal] = tmp
            return tmp

def solve(caseVal):
    if caseVal <= 20:
        return caseVal

    if caseVal <= 101:
        return solveSlow(caseVal)

    size = len(str(caseVal))
    res = caseVal % 10**(size - 1)
    if res == 0:
        return solve(caseVal - 1) + 1
    if res == 1:
        tmp = reverse(caseVal)
        if caseVal != tmp:
            return solve(tmp) + 1
        else:
            return solve(tmp - 2) + 2

    tmpPow = 10**((size+1) // 2)
    res = caseVal % tmpPow
    if res == 0:
        return solve(caseVal - 1) + 1
    if res == 1:
        return solve(reverse(caseVal)) + 1

    return solve((caseVal // tmpPow) * tmpPow + 1) + res - 1

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
