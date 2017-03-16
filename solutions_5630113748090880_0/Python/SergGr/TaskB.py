import itertools
import time
import operator
# import collections
from collections import Counter
from fractions import gcd
from random import randint
import random

inputFileName = "test.in"
inputFileName = "B-small-attempt0.in"
# inputFileName = "B-small-attempt1.in"
# inputFileName = "B-small-attempt2.in"
# inputFileName = "B-small-attempt3.in"
# inputFileName = "B-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def calcSingleTest(f):
    line = f.readline()
    N = int(line)
    arr = []
    all_h = Counter()
    for i in xrange(2 * N - 1):
        line = f.readline()
        l = map(int, line.split())
        arr.append(l)
        all_h.update(l)

    odds = [k for (k, v) in all_h.iteritems() if v % 2 == 1]
    odds = list(sorted(odds))
    if len(odds) == N:
        return str.join(' ', map(str, odds))

    return 0


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
