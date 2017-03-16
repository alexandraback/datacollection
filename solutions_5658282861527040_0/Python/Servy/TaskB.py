from math import log2

__author__ = 'Servy'

import sys

def waysToGet0(a, prefix, n):
    valueA = int(a[0:len(prefix)], 2)
    valuePrefix = int(prefix, 2)
    if valueA == valuePrefix:
        if a[len(prefix) + 1] == "0":
            return 1
        else:
            return 2
    elif valueA < valuePrefix:
        return 0
    else:
        return 2


def waysToGet1(a, prefix, n):
    valueA = int(a[0:len(prefix)], 2)
    valuePrefix = int(prefix, 2)
    if valueA == valuePrefix:
        if a[len(prefix) + 1] == "1":
            return 1
        else:
            return 0
    elif valueA < valuePrefix:
        return 0
    else:
        return 1



def calc(a, b, k, prefix, n):
    if len(prefix) >= n:
        return 1
    return 0

def solve(a, b, k):
    result = 0
    for i in range(a):
        for j in range(b):
            if i & j < k:
                result += 1
    return result

testNumber = int(sys.stdin.readline().strip())
for test in range(1, testNumber + 1):
    (a, b, k) = map(int, sys.stdin.readline().split())
    print("Case #%d: %d" % (test, solve(a, b, k)))