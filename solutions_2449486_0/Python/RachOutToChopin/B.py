#!/usr/bin/python
import math
import string
import sys

def solve(line):
    (N, M) = [ int(x) for x in f.readline().strip().split(' ') ]
    cur = [ [ 100 ] * M for i in range(N)]
    desired = []
    for i in range(N):
        desired.append([ int(x) for x in f.readline().strip().split(' ') ])
    for i in range(N):
        # Mow each row the maximum amount
        cur[i] = [ max(desired[i]) ] * M
    for j in range(M):
        # Mow each column the maximum amount
        col = [ row[j] for row in desired ]
        mowHeight = max(col)
        for i in range(N):
            cur[i][j] = min(cur[i][j], mowHeight)
    return 'YES' if (cur == desired) else 'NO'

f = open(sys.argv[1])
NUM_CASES = int(f.readline())  # number of lines
for qq in range(NUM_CASES):
    print "Case #%d: %s" % (qq+1, solve(f))
