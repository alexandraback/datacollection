#!/usr/local/bin/python

import sys

def solve(t):
    N = int(sys.stdin.readline().rstrip())

    cnts = {}
    for i in range(2*N-1):
        l = map(int, sys.stdin.readline().rstrip().split())
        for num in l:
            cnts[num] = cnts.get(num, 0) + 1

    cands = sorted(k for k,v  in cnts.iteritems() if v%2==1)
    assert len(cands) == N
    print 'Case #{}: {}'.format(t, ' '.join(map(str, cands)))

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
