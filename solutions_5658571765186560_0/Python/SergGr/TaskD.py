import itertools
import time
import operator
#import collections
from collections import Counter

#inputFileName = "test.in"
inputFileName = "D-small-attempt0.in"
#inputFileName = "D-small-attempt1.in"
#inputFileName = "D-small-attempt2.in"
#inputFileName = "D-small-attempt3.in"
#inputFileName = "D-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime

FIT = 'GABRIEL'
CANT_FIT = 'RICHARD'

def calcSingleTest(f):
    line = f.readline()
    X = int(line.split()[0])
    R = int(line.split()[1])
    C = int(line.split()[2])

    if R * C % X != 0:
        return CANT_FIT

    # can worst L-shaped (right angle) be fitted?
    mi = min(R, C)
    if mi < (X + 1) / 2:
        return CANT_FIT
    # can worst I-shaped (straight) be fitted?
    ma = max(R, C)
    if ma < X :
        return CANT_FIT

    if X == 1:
        return FIT
    elif X == 2:
        return FIT
    elif X == 3:
        if mi == 1:
            return CANT_FIT
        return FIT
    elif X == 4:
        if mi == 2:
            return CANT_FIT
        return FIT

    if X >= 7:
        return CANT_FIT
    return CANT_FIT

with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            r1 = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, r1))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))