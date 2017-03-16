import threading
import sys
# Increase max stack size from 8MB to 512MB
# resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10 ** 6)

import itertools
import random
import time
import operator
import collections
from collections import Counter

# from scipy.spatial import qhull
# from scipy.spatial import ConvexHull
# import numpy as np
from math import *

inputFileName = "test.in"
# inputFileName = "C-small-practice.in"
inputFileName = "C-small-attempt0.in"
inputFileName = "C-small-attempt1.in"
# inputFileName = "C-small-attempt2.in"
# inputFileName = "C-small-attempt3.in"
# inputFileName = "C-large.in"
outputFileName = inputFileName[:-3] + ".out"

startTime = time.time()
print startTime


def check(gs, K):
    jp = collections.defaultdict(int)
    ps = collections.defaultdict(int)
    js = collections.defaultdict(int)
    for (j, p, s) in gs:
        jp[(j, p)] = jp[(j, p)] + 1
        if jp[(j, p)] > K:
            return False
        ps[(p, s)] += 1
        if ps[(p, s)] > K:
            return False
        js[(j, s)] += 1
        if js[(j, s)] > K:
            return False
    return True


def bruteForce(J, P, S, K):
    js = list(xrange(1, J + 1))
    ps = list(xrange(1, P + 1))
    ss = list(xrange(1, S + 1))
    all = list(itertools.product(js, ps, ss))
    N = len(all)
    em = len(js) * len(ps) * min(K, len(ss))

    for m in xrange(em, 0, -1):
        for cur in itertools.combinations(all, m):
            # print(cur)
            if check(cur, K):
                return (m, cur)
    pass
    # b = []
    # m = 0
    # for bm in xrange(0, 2 ** N + 1):
    #     cur = []
    #     p = 1
    #     for i in xrange(N):
    #         if p & bm != 0:
    #             cur.append(all[i])
    #         p *= 2
    #
    #     if len(cur) > m and (K >= len(js) * len(ps) or check(cur, K)):
    #         # print cur
    #         m = len(cur)
    #         b = cur
    # return (m, b)


def calcSingleTest(f):
    line = f.readline()
    arr = map(int, line.split())
    K = arr[3]
    gs = arr[:3]

    print str(gs) + " " + str(K)

    (m, b) = bruteForce(gs[0], gs[1], gs[2], K)
    return str(m) + '\n' + '\n'.join(map(lambda (j, p, s): str(j) + ' ' + str(p) + ' ' + str(s), b))


def main():
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

main()
