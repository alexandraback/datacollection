#! /usr/bin/python

import os, sys

def debug(msg):
    if len(sys.argv) > 1 and sys.argv[1] == '-d':
        sys.stderr.write(msg)
        sys.stderr.write('\n')

T = int(sys.stdin.readline())
input_data = {}

def solve_brute(A, B, K):
    win = 0
    for i in range(0, A):
        for j in range(0, B):
            r = i & j
            if r < K:
                win += 1
    return win
# For each test case
for t in range(1, T+1):
    A, B, K = [int(x) for x in sys.stdin.readline().split(' ')]
    debug('A %s, B %s, K %s' % (A, B, K))
    ret = solve_brute(A, B, K)
    sys.stdout.write('Case #%s: %s\n' % (t, ret))
