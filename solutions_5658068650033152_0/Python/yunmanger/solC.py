import math
from fractions import gcd

def sol(N, M, K):
    r = K
    for i in xrange(2, N + 1):
        for j in xrange(2, M + 1):
            for k in xrange(5):
                if i * j - k >= K and (i - 1) * 2 + 2 * (j - 1) - k < r:
                    r = (i - 1) * 2 + 2 * (j - 1) - k
    return r

import sys
readline = sys.stdin.readline

line = readline()
tn = int(line)
for i in xrange(1, tn + 1):
    N, M, K = map(int, readline().split(" "))
    print 'Case #{}: {}'.format(i, sol(N, M, K))

