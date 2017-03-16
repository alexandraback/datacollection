
from math import ceil

T = int(raw_input())

def getIndex(K, coveredRange):
    ind = 1
    for index, i in enumerate(coveredRange):
        ind += (K ** index) * i
    return ind

for i in xrange(T):
    nums = ""

    line = raw_input().split()
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])

    stringSize = K ** C

    maxNumDependants = C
    minNumOfCells = int(ceil(K / float(maxNumDependants)))
    neededDependants = range(K)

    if S < minNumOfCells:
        nums = "IMPOSSIBLE "
    else:
        for cellIndex in xrange(minNumOfCells):
            neededCoveredRange = neededDependants[cellIndex * maxNumDependants:(cellIndex + 1) * maxNumDependants]
            nums += str(getIndex(K, neededCoveredRange)) + " "

    print 'Case #%d: %s' % (i + 1, nums[:-1]),
    print
