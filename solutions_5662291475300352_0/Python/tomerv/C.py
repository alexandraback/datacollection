import sys
import copy
import itertools
from collections import defaultdict
import math
import datetime

epsilon = 1e-6


def log(msg):
    print(msg, file=sys.stderr)

def solve(hikers):
    assert(len(hikers) <= 2)
    if len(hikers) < 2:
        return 0
    first = hikers[0]
    second = hikers[1]
    if first[0] > second[0]:
        first, second = second, first
    d1 = first[0]
    m1 = first[1]
    d2 = second[0]
    m2 = second[1]
    # if m1 * (3*360 - d1) <= m2 * (360 - d2):
    #     return 2
    if m1 * (2*360 - d1) <= m2 * (360 - d2):
        return 1
    if m2 * (2*360 - d2) <= m1 * (360 - d1):
        return 1
    return 0

def testcase():
    n = int(sys.stdin.readline().strip())
    hikers = [] # (start, speed)
    for i in range(n):
        d, h, m = map(int, sys.stdin.readline().strip().split())
        for j in range(h):
            hikers.append((d, m+j))
    solution = solve(hikers)
    testcase.id += 1
    print('Case #{}: {}'.format(testcase.id, solution))
testcase.id = 0

start = datetime.datetime.now()
t = int(sys.stdin.readline())
for i in range(t):
    log('Case #{}'.format(i+1))
    testcase()
log(datetime.datetime.now() - start)

