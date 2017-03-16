import sys
import collections
import math
import itertools
from itertools import combinations

def rl():
    return tuple(map(int, raw_input().strip().split()))

def arr2d(row, col, v=0):
    return [[v for _ in xrange(col)] for _ in xrange(row)]

class SubsetSum(object):
    def is_subset(self, x, numbers):
        #print 'is_subset=== ' + str(locals())
        # dp[i][m] : true if numbers[0...i] has sum m subset, false otherwise
        dp = arr2d(len(numbers), x+1, 0)
        for i in range(len(numbers)):
            dp[i][0] = 1
            if x >= numbers[i]:
                dp[i][numbers[i]] = 1
        for m in range(x+1):
            for i in range(1, len(numbers)):
                dp[i][m] = dp[i-1][m]
                if m >= numbers[i]:
                    dp[i][m] |= dp[i-1][m-numbers[i]]
        return dp[len(numbers)-1][x]

def solve(CDV, denom):
    #print '====== ' + str(locals())
    C = CDV[0]
    V = CDV[2]
    d = set(i for i in range(1,31))
    cnt = 0
    ok = False
    while not ok:
        for dd in itertools.combinations(d-set(denom), cnt):
            ddd = set(dd) | set(denom)
            for v in xrange(1,V+1):
                s = SubsetSum()
                if not s.is_subset(v, list(ddd)*C):
                    break
            else:
                ok = True
                break
        if not ok:
            cnt += 1
    return cnt
if __name__ == '__main__':
    for case in range(int(raw_input())):
        print 'Case #%d: %d' % (case+1, solve(rl(), rl()))