import sys
import itertools
import math
import collections
import functools

def inputInts():
    return map(int, raw_input().split())

def lookPosition(startIdx, numIndices):
    if startIdx + numIndices > K:
        numIndices = K - startIdx
    return lookPositionAux(startIdx, startIdx+1, numIndices-1, C-1)

# pos: position in the current row
# idx: index to look at, in [0,K[
# numIndices: how many indices to look at
# c: how many times we need to apply the transform
def lookPositionAux(pos, idx, numIndices, c):
    if c == 0:
        return pos
    if numIndices == 0:
        return lookPositionAux(pos * K + idx - 1, idx, 0, c-1)
    return lookPositionAux(pos * K + idx, idx+1, numIndices-1, c-1)

T = int(raw_input())
for testId in range(T):
    K, C, S = inputInts()

    if S * C < K:
        print "Case #{:d}: IMPOSSIBLE".format(testId+1)
        continue

    res = []
    for k in xrange(0, K, C):
        res.append(lookPosition(k, C))

    print "Case #{:d}: {}".format(testId+1, " ".join([str(i+1) for i in res]))
