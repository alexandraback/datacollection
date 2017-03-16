#!/usr/bin/python

def solve():
    N,M = map(int, raw_input().split())
    rows = [map(int, raw_input().split()) for i in xrange(N)]
    rowmax = [1]*N
    colmax = [1]*M
    for r in xrange(N):
        for c in xrange(M):
            rowmax[r] = max(rowmax[r], rows[r][c])
            colmax[c] = max(colmax[c], rows[r][c])
    for r in xrange(N):
        for c in xrange(M):
            if rows[r][c] != min(rowmax[r], colmax[c]):
                return 'NO'
    return 'YES'

T = input()
for t in xrange(T):
    print 'Case #%s: %s' % (t+1, solve())
