#!/usr/bin/python3

import sys

T = int(sys.stdin.readline())
caseNum = 0

def solve(A, N, motes):
    # motes should be sorted list
    ans = N # remove all existing motes
    if A == 1:
        return ans # Armin cannot grow :-(
    added = 0
    for i in range(1, N+1):
        m = motes[i-1]
        # gobble up to i-th mote
        while m >= A:
            added += 1
            A += A-1
        A += m
        if added + (N-i) < ans:
            ans = added + (N-i)
    return ans

while caseNum < T:
    caseNum += 1
    A, N = map(int, sys.stdin.readline().strip().split(' '))
    motes = sorted(map(int, sys.stdin.readline().strip().split(' ')))
    
    print("Case #{0}: {1}".format(caseNum, solve(A, N, motes)))
