import itertools
import random
import time
import operator
#import collections
from collections import Counter


inputFileName = "test.in"
#inputFileName = "C-small-1-attempt0.in"
#inputFileName = "C-small-1-attempt1.in"
#inputFileName = "C-small-1-attempt2.in"
#inputFileName = "C-small-1-attempt3.in"
inputFileName = "C-small-1-attempt4.in"


#inputFileName = "C-small-attempt0.in"
#inputFileName = "C-small-attempt1.in"
#inputFileName = "C-small-attempt2.in"
#inputFileName = "C-small-attempt3.in"
#inputFileName = "C-large.in"
#inputFileName = "C-small-practice.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def calcSingleTest2(f):
    line = f.readline()
    N = int(line)
    hs = []
    for i in xrange(N):
        line = f.readline()
        p = int(line.split()[0])
        c = int(line.split()[1])
        s0 = int(line.split()[2])
        for j in xrange(c):
            hs.append([p, s0 + j])
    print hs
    h1 = hs[0]
    h2 = hs[1]
    #    if h1[0] < h2[0]:
    #        h1, h2 = h2, h1
    L = 360
    t1 = (L - h1[0]) * h1[1]
    t2 = (L - h2[0]) * h2[1]
    dt1 = (0.0 + t1) / L
    dt2 = (0.0 + t2) / L
    if t2 < t1:
        h1, h2 = h2, h1
        t1, t2 = t2, t1
        dt1, dt2 = dt2, dt1

    print 't1 = {0}, t2 = {1}, t1+h1 = {2}, {3}'.format(dt1, dt2, dt1 + h1[1], h1[0])
    b1 = dt1 + h1[1] < dt2
    b2 = t1 + L * h1[1] < t2
    if b1 != b2:
        raise RuntimeError("AAAAAAAAAAAA")
    if t1 + L * h1[1] < t2:
        return 1
    else:
        return 0


def calcSingleTest(f):
    line = f.readline()
    N = int(line)
    hs = []
    for i in xrange(N):
        line = f.readline()
        p = int(line.split()[0])
        c = int(line.split()[1])
        s0 = int(line.split()[2])
        for j in xrange(c):
            hs.append([p, s0 + j])
    print hs
    h1 = hs[0]
    h2 = hs[1]
    L = 360
    s1 = h1[1]
#    p11 = h1[0] + L / h1[1] * s1
    p21 = h2[0] + L / h2[1] * s1
    s2 = h2[1]
    p12 = h1[0] + L / h1[1] * s2
#    p22 = h2[0] + L / h2[1] * s2
    b1 = p21 <= L
    b2 = p12 <= L

    t1 = (L - h1[0]) * h1[1]
    t2 = (L - h2[0]) * h2[1]
    dt1 = (0.0 + t1) / L
    dt2 = (0.0 + t2) / L

    if t2 < t1:
        print "Switched"
        h1, h2 = h2, h1
        t1, t2 = t2, t1
        dt1, dt2 = dt2, dt1

    r1 = dt1 + h1[1] < dt2
    r2 = b1 and b2

    if b1 or b2:
        return 1
    else:
        return 0


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

