#!/usr/bin/env python

import math

IMPOSSIBLE = 'IMPOSSIBLE'

def getNumberOfTestsNeeded(K, C):
    return int(math.ceil(float(K) / C))

def getWhereToTest(K, C, testNo):
    if K == 1:
        return 0
    i = testNo * C
    end = (testNo + 1) * C
    if K < end:
        end = K
    whereToTest = 0
    while i < end:
        whereToTest *= K
        whereToTest += i
        i += 1
    return whereToTest
			
T = int(raw_input().strip())
for testCaseNo in range(T):
    print 'Case #' + str(testCaseNo + 1) + ':',
    K, C, S = map(int, raw_input().strip().split(' '))
    numberOfTestsNeeded = getNumberOfTestsNeeded(K, C)
    if numberOfTestsNeeded > S:
        print IMPOSSIBLE
    else:
        for i in range(numberOfTestsNeeded):
            print getWhereToTest(K, C, i) + 1,
        print
