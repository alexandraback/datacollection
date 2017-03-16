import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())


T = int(raw_input())
for testId in range(T):
    J, P, S, K = inputInts()

    res = []
    pairsJP = {}
    pairsJS = {}
    pairsPS = {}
    for j in xrange(J):
        for p in xrange(P):
            for s in xrange(S):
                jp = str(j)+str(p)
                if jp not in pairsJP:
                    pairsJP[jp] = 0
                if pairsJP[jp] >= K:
                    continue
                js = str(j)+str(s)
                if js not in pairsJS:
                    pairsJS[js] = 0
                if pairsJS[js] >= K:
                    continue
                ps = str(p)+str(s)
                if ps not in pairsPS:
                    pairsPS[ps] = 0
                if pairsPS[ps] >= K:
                    continue
                pairsJP[jp] += 1
                pairsJS[js] += 1
                pairsPS[ps] += 1
                res.append([j+1,p+1,s+1])

    print "Case #{:d}: {:d}".format(testId+1, len(res))
    for row in res:
        print ' '.join(map(str, row))
