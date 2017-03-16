#!/usr/bin/env python

import sys

impossible = "IMPOSSIBLE"

def solve(initialKeys, Ti, keys):
    N = len(Ti)

    def countKeys(left):
        numKeys = [0] * 201
        for key in initialKeys:
            numKeys[key] += 1
        for i in xrange(N):
            if (left & (1 << i)) == 0:
                for key in keys[i]:
                    numKeys[key] += 1
        for i in xrange(N):
            if (left & (1 << i)) == 0:
                numKeys[Ti[i]] -= 1
                if numKeys[Ti[i]] < 0:
                    return None
        return numKeys

    answer = [None] * (1 << N)
    answer[0] = []
    for left in xrange(1, len(answer)):
        numKeys = countKeys(left)
        if numKeys is None:
            continue
        for c in xrange(N):
            if numKeys[Ti[c]] == 0:
                continue
            b = 1 << c
            if (left & b) > 0 and not answer[left ^ b] is None:
                answer[left] = list(answer[left ^ b])
                answer[left].append(c)
                break
    if answer[-1] is None:
        return impossible
    answer[-1].reverse()
    return ' '.join([ str(c + 1) for c in answer[-1] ])

def readInts():
    return [ int(s) for s in sys.stdin.readline().split() ]

T = int(sys.stdin.readline())
for t in xrange(T):
    inputs = readInts()
    N = inputs[1]
    initialKeys = readInts()
    Ti = [0] * N
    keys = [0] * N
    for i in xrange(N):
        inputs = readInts()
        Ti[i] = inputs[0]
        keys[i] = inputs[2:]
    res = solve(initialKeys, Ti, keys)
    print "Case #%d: %s" % (t + 1, res)
