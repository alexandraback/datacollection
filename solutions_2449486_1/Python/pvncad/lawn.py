#/usr/local/bin/python

import sys

T = int(sys.stdin.readline())

for caseno in xrange(T):
    N, M = [int(x) for x in sys.stdin.readline().split()]

    grid = [ ]

    for i in xrange(N):
        grid.append([int(x) for x in sys.stdin.readline().split()])

    rowmax = [ 0 ] * N
    for i in xrange(N):
        rowmax[i] = max(grid[i])

    colmax = [ 0] * M

    for j in xrange(M):
        for i in xrange(N):
            colmax[j] = max(colmax[j], grid[i][j])

    ans = True

    for i in xrange(N):
        if not ans:
            break;
        for j in xrange(M):
            if grid[i][j] != colmax[j] and grid[i][j] != rowmax[i]:
                ans = False
                break

    res = "NO"

    if ans:
        res = "YES"

    print "Case #%d: %s" % (caseno + 1, res)
