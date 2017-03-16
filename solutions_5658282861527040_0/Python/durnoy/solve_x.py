from __future__ import print_function
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")


T = int(f.readline().strip())

for case_id in range(1, T+1):
    A, B, K = map(int, f.readline().strip().split())
    #~ print(A, B, K)

    r = 0
    for i in xrange(0, A):
        for j in xrange(0, B):
            if i & j < K:
                r += 1
    print(str.format('Case #{0}: {1}', case_id, r))
