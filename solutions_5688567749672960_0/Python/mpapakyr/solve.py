#! /usr/bin/python

import os, sys, copy

def debug(msg):
    if len(sys.argv) > 1 and sys.argv[1] == '-d':
        sys.stderr.write('%s' % msg)
        sys.stderr.write('\n')

def solve(N):
    #dd = {} # too slow
    #dd[0] = 0
    dd = [0] + [None]*N
    for i in range(1, N+1):
        if dd[i] is not None:
            dd[i] = min(dd[i], 1+dd[i-1])
        else:
            dd[i] = 1 + dd[i-1]
        rvsed = int(str(i)[::-1])
        if rvsed <= N:
            if dd[rvsed] is None:
                dd[rvsed] = 1 + dd[i]
    return dd
    


T = int(sys.stdin.readline())
# For each test case
dynamic = solve(1000000)
for t in range(1, T+1):
    N = int(sys.stdin.readline())
    ret = dynamic[N]
    sys.stdout.write('Case #%s: %s\n' % (t, ret))
