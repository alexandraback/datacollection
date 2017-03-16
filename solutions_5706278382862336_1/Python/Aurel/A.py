import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(1000)


def solve(P, Q):
    # how many at gen 40?
    if (2**40 * P) % Q <> 0:
        return "impossible"

    # let's put them all on the same side and check when we get the last 1/1
    res = 40
    count1s = 2**40 * P / Q
    while count1s >= 2 and res > 0:
        res -= 1
        count1s /= 2
        
    return str(res)

T = int(raw_input())
for testId in range(T):
    P, Q = map(int, raw_input().split('/'))

    print "Case #{:d}: {:s}".format(testId+1, solve(P, Q))
