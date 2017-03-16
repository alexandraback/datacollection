import sys
import itertools
import math
import collections
import functools

def inputInts():
    return map(int, raw_input().split())

T = int(raw_input())
for testId in range(T):
    K, C, S = inputInts()

    # We only solve the small input for now
    if S < K:
        print "Case #{:d}: UNSUPPORTED".format(testId+1)
        continue

    res = [0 for i in xrange(S)]
    for i in xrange(S):
        res[i] = i
        for c in xrange(1, C):
            res[i] = i + res[i] * K

    print "Case #{:d}: {}".format(testId+1, " ".join([str(i+1) for i in res]))
