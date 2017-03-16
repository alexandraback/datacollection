import itertools
import time
import operator
#import collections
from collections import Counter
from collections import OrderedDict


#inputFileName = "test.in"
#inputFileName = "B-small-attempt0.in"
#inputFileName = "B-small-attempt1.in"
#inputFileName = "B-small-attempt2.in"
#inputFileName = "B-small-attempt3.in"
inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def calcSingleTest(f):
    line = f.readline()
    line = f.readline()
    d = map(int, line.split())
    d = sorted(d, reverse=True)
    #    dc = Counter(d)
    #    du = list(sorted(dc.iterkeys(), reverse=True))
    ma = max(d)
    best = ma
    best_cut = 0
    for eat in xrange(1, ma):
        cnt = 0
        for p in d:
            cnt += int((p - 1) / eat)
        cur = eat + cnt
        if cur < best:
            best = cur
            best_cut = eat

    return best


with open(inputFileName) as inpF:
    with open(outputFileName, 'w') as outF:
        line = inpF.readline()
        testsCount = int(line)
        for i in xrange(1, testsCount + 1):
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            res = calcSingleTest(inpF)
            print '--------  {0}/{1} {2} --------------------------'.format(i, testsCount, (time.time() - startTime))
            print ' '
            outF.write('Case #{0}: {1}\n'.format(i, res))
            outF.flush()

print "Finished!!!! Total time = {0}".format((time.time() - startTime))