import sys
import collections

T = int(raw_input())
for t in xrange(1, T + 1):
    result = 0
    A, B, K = map(int, raw_input().split())
    for i in xrange(A):
        for j in xrange(B):
            if i & j < K:
                result += 1
    print "Case #{0}: {1}".format(t, result)

