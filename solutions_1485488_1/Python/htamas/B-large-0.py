#!/usr/bin/env python

from sys import stdin
from heapq import heappush, heappop

dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

T = int(stdin.readline().strip())
for tc in xrange(1, T+1):
    H, N, M = map(int, stdin.readline().strip().split(" "))
    C = []
    for i in xrange(N):
        C.append(map(int, stdin.readline().strip().split(" ")))
    F = []
    for i in xrange(N):
        F.append(map(int, stdin.readline().strip().split(" ")))

    p = [(0, 0, 0)]
    m = [[0 for _ in xrange(M)] for _ in xrange(N)]
    while p:
        t, x, y = heappop(p)
        if m[y][x]: continue
        m[y][x] = 1
        if (x, y) == (M-1, N-1):
            break
        for dx, dy in dirs:
            nx = x + dx
            ny = y + dy
            if nx < 0:  continue
            if nx >= M: continue
            if ny < 0:  continue
            if ny >= N: continue
            if C[ny][nx] - F[ny][nx] < 50: continue
            if C[ny][nx] - F[y][x]   < 50: continue
            if C[y][x]   - F[ny][nx] < 50: continue
            nt = max(t, H - C[ny][nx] + 50)
            if nt:
                if H - nt - F[y][x] < 20:
                    nt += 100
                else:
                    nt += 10
            heappush(p, (nt, nx, ny))

    r = "%02d" % t
    print "Case #" + str(tc) + ": " + r[:-1] + "." + r[-1]

