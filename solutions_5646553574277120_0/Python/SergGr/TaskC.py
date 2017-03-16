import itertools
import random
import time
import operator
#import collections
from collections import Counter

inputFileName = "test.in"
#inputFileName = "C-small-practice.in"

#inputFileName = "C-small-attempt0.in"
inputFileName = "C-small-attempt1.in"
inputFileName = "C-small-attempt2.in"
#inputFileName = "C-small-attempt3.in"
#inputFileName = "C-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def list_powerset(lst):
    # the power set of the empty set has one element, the empty set
    result = [[]]
    for x in lst:
        result.extend([subset + [x] for subset in result])
    return result


def canFit(v, ds):
    for d in list_powerset(ds):
        s = sum(d)
        if s == v:
            return True
    return False


def calcSingleTest(f):
    line = f.readline()
    C = int(line.split()[0])
    D = int(line.split()[1])
    V = int(line.split()[2])
    line = f.readline()
    ds = map(int, line.split())
    ds0 = list(sorted(ds))
    ds = list(sorted(ds))
    print 'C={0}, D={1}, V={2}'.format(C, D, V)
    print ds
    if C != 1:
        return "AAA"
    r = 0

    for s in xrange(V + 1):
        if not canFit(s, ds):
            print "Adding " + str(s)
            ds.append(s)
            ds = list(sorted(ds))
            r += 1
    return r


with open(inputFileName) as inpF:
    random.seed(0)
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