#/usr/local/bin/python

import sys
import math

T = int(sys.stdin.readline())

for caseno in xrange(T):
    A, B, K = [int(x) for x in sys.stdin.readline().split()]

    ans = 0;

    for x in xrange(A):
        for y in xrange(B):
            if (x & y) < K:
                ans += 1

    print "Case #%d: %s" % (caseno + 1, ans)

