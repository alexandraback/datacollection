import sys

def getInputs():
    if len(sys.argv)-1 > 0:
        filename = sys.argv[1]
        with open(filename) as f:
            nb = int(f.readline())
            inputStr = [f.readline().split() for i in range(nb)]
            inputStr = [map(int, list(s[1][:int(s[0])+1])) for s in inputStr]
            return inputStr

def solve(caseVal):
    missingCount = 0
    peopleCount = 0
    for i, val in enumerate(caseVal):
        if i > peopleCount+missingCount:
            missingCount += i-(peopleCount+missingCount)
        peopleCount += val
    return missingCount

# with: 0 <= caseId < N
def writeOutput(caseId, result):
    print 'Case #%d: %d' % (caseId+1, result)

for caseId, caseVal in enumerate(getInputs()):
    writeOutput(caseId, solve(caseVal))
