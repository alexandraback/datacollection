import itertools
import random
import time
import operator
# import collections
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


def brute_force(N, arr, all_fr):
    b = 1
    all = list(range(N))

    def check_order(order):
        ll = len(order)
        for x in xrange(ll):
            cur = order[x]
            left = order[(ll + x - 1) % ll]
            right = order[(x + 1) % ll]
            if left != arr[cur] and right != arr[cur]:
                return False
        return True

    def check_length(l):
        for vs in itertools.combinations(all, l):
            for order in itertools.permutations(vs):
                if check_order(order):
                    return True
        return False

    for l in xrange(2, N + 1):
        if check_length(l):
            b = l
    return b


def calcSingleTest(f):
    line = f.readline()
    N = int(line)
    line = f.readline()
    arr = map(lambda x: x - 1, map(int, line.split()))
    all_fr = dict()
    for x in xrange(N):
        all_fr[x] = []

    for x in xrange(N):
        all_fr[arr[x]].append(x)

    order = []
    visited = set()

    def visit(v):
        if v in visited:
            return
        visited.add(v)
        visit(arr[v])
        order.insert(0, v)
        return

    for x in xrange(N):
        visit(x)

    s_comps = [-1] * N
    s_comps_count = [0] * N

    def assign(v, root):
        if s_comps[v] != -1:
            return
        s_comps_count[root] += 1
        s_comps[v] = root
        for v1 in all_fr[v]:
            assign(v1, root)
        return

    for x in order:
        assign(x, x)

    tails = [0] * N
    for x in order:
        c = s_comps[x]
        if s_comps_count[c] != 1:
            continue
        if tails[x] + 1 > tails[arr[x]]:
            tails[arr[x]] = tails[x] + 1

    good_comps = [xx for xx in xrange(0, N) if s_comps_count[xx] == 2]
    good_v = [vv for vv in xrange(0, N) if s_comps_count[s_comps[vv]] == 2]

    for x in good_v:
        c = s_comps[x]
        if c == x:
            continue
        else:
            tails[c] += tails[x]

    m = max(s_comps_count)
    s = 0
    for x in good_v:
        c = s_comps[x]
        if c == x:
            tails[x] += 2
            s += tails[x]
            tails[x] = -tails[x]

    print N
    print "arr = " + str(arr)
    print all_fr
    print order
    print "cmp = " + str(s_comps)
    print "cnt = " + str(s_comps_count)
    print good_comps
    print good_v
    print tails
    res = max(s, m)
    print "res = {0}, max = {1}, sum = {2}".format(res, m, s)

    # if True and (N < 10 or res < 10):
    if False:
        res2 = brute_force(N, arr, all_fr)
        if res != res2:
            print "AAAAAA " + " res = " + str(res) + " res2 = " + str(res2)
            raise RuntimeError("AAAAAA " + str(res) + " res2 = " + str(res2))
        else:
            print "Good"
    else:
        print "!!!Skip"
    return res


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
