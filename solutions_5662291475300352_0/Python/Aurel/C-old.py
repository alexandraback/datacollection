import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())

def encountersStrictlyBefore(t):
    res = 0
    for h in hikers:
        if h[0] >= t:
            continue
        remaining = t - h[0]
        d = remaining / h[1]
        res += int(d)
    return res

T = int(raw_input())
for testId in range(T):
    N = input()
    hikers = []
    arrivals = []
    for n in xrange(N):
        D, H, M = inputInts()
        for h in xrange(H):
            revolutionTime = M+h
            hikers.append([(360 - D) * revolutionTime / 360.0, revolutionTime])
            arrivals.append((360 - D) * revolutionTime / 360.0)

    arrivals.sort()
    

    
    H = len(arrivals)

    # We will arrive immediately after one of the hikers. Which one?
    best = H
    for h in xrange(H):
        # If multiple hikers arrive at the same time, we can skip the first.
        if h < H-1 and arrivals[h] == arrivals[h+1]:
            continue

        # We arrive immediately after t=arrivals[h]. How many encounters?

        # First, we encounter all the hikers that arrive after h.
        res = H - h - 1

        # We might also re-encounter some of the faster hikers
        res += encountersStrictlyBefore(arrivals[h])
        #print "Arriving after t = ", arrivals[h], ", res = ", res, " (with init = ", (H-h-1), ")"

        best = min(best, res)

    print "Case #{:d}: {:d}".format(testId+1, best)
