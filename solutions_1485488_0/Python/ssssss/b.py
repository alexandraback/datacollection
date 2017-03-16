#!/usr/bin/python3

import sys
import heapq

def qadd(h, t, H, C, F, x, y, xx, yy):
    if C[xx][yy] - F[x][y] < 50: return
    if C[x][y] - F[xx][yy] < 50: return
    if C[xx][yy] - F[xx][yy] < 50: return
    H -= t*10
    tt = max(0, (50 - (C[xx][yy] - H))/10)
    H -= tt*10
    if t > 0 or tt > 0:
        if H - F[x][y] >= 20:
            tt += 1
        else:
            tt += 10
    heapq.heappush(h, (t+tt, xx, yy))

def case():
    H,N,M = [int(x) for x in sys.stdin.readline().split()]
    C = []
    for i in range(0,N):
        C.append([int(x) for x in sys.stdin.readline().split()])
    F = []
    for i in range(0,N):
        F.append([int(x) for x in sys.stdin.readline().split()])
    scanned = []
    for i in range(0,N):
        scanned.append([0 for j in range(0,M)])
    h = []
    heapq.heappush(h, (0.0, 0, 0))
    while len(h) > 0:
        key, x,y = heapq.heappop(h)
        if x == N-1 and y == M-1:
            return round(key,7)
        scanned[x][y] = True
        if x > 0 and scanned[x-1][y] == False:
            qadd(h, key, H, C, F, x, y, x-1, y)
        if x < N-1 and scanned[x+1][y] == False:
            qadd(h, key, H, C, F, x, y, x+1, y)
        if y > 0 and scanned[x][y-1] == False:
            qadd(h, key, H, C, F, x, y, x, y-1)
        if y < M-1 and scanned[x][y+1] == False:
            qadd(h, key, H, C, F, x, y, x, y+1)

T = int(sys.stdin.readline())
for i in range(1,T+1):
    r = case()
    print("Case #%s: %s" % (i, r))
    

