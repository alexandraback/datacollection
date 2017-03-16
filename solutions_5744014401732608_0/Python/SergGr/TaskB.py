import threading
import sys
from  collections import Counter
# Increase max stack size from 8MB to 512MB
# resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10 ** 6)

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


def bruteForce(B, M):
    e = B * (B - 1) / 2

    for p in xrange(1, 2 ** e):
        cs = [0] * B
        cs[0] = 1
        # print '--------------------------'
        for i in xrange(1, B):
            for j in xrange(i):
                edgeIndex = i * (i - 1) / 2 + j
                if 2 ** edgeIndex & p != 0:
                    cs[i] += cs[j]
                    # print (i, j)
                    # print (j, i)
        if cs[B - 1] == M:
            # print "{0:b}".format(p)
            # print(cs)
            m = []
            for y in xrange(0, B - 1):
                row = [0] * B
                m.append(row)
                for x in xrange(y + 1, B):
                    i = x
                    j = y
                    edgeIndex = i * (i - 1) / 2 + j
                    if 2 ** edgeIndex & p != 0:
                        row[x] = 1
            m.append([0] * B)

            # s = '\n'.join(map(lambda r: ' '.join(map(str, r)), m))
            s = '\n'.join(map(lambda r: ''.join(map(str, r)), m))
            return s
    return ''


def calcSingleTest(f):
    line = f.readline()
    B = int(line.split()[0])
    M = int(line.split()[1])
    if M > 2 ** B:
        return 'IMPOSSIBLE'
    bruteRes = bruteForce(B, M)
    if len(bruteRes) == 0:
        print (B, M)
        return 'IMPOSSIBLE'
    return 'POSSIBLE' + '\n' + bruteRes

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
