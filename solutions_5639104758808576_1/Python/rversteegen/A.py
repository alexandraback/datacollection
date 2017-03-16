#!/usr/bin/python

import sys


def readline():
    return sys.stdin.readline().strip().split()

def readints():
    return [int(x) for x in readline()]


T, = readints()
for testcase in range(T):
    s_max, str = readline()
    s_max = int(s_max)
    total = 0
    needed = 0
    for idx, char in enumerate(str):
        if total < idx:
            needed += idx - total
            total = idx
        total += int(char)

    print "Case #%d: %d" % (testcase + 1, needed)
