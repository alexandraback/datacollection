#!/usr/bin/env python

Ncases = int(raw_input())

def getrow(lawn, i):
    return lawn[i]

def getcolumn(lawn, i):
    col = [None] * len(lawn)
    for j in range(len(lawn)):
        col[j] = lawn[j][i]
    return col

def solve(icase, lawn):
    N = len(lawn)
    M = len(lawn[0])
    for i in range(N):
        for j in range(M):
            desiredHeight = lawn[i][j]
            maxHeightRow = max(getrow(lawn, i))
            maxHeightCol = max(getcolumn(lawn, j))
            if maxHeightRow > desiredHeight and \
               maxHeightCol > desiredHeight:
                print('Case #%d: NO' % (icase))
                return
    print('Case #%d: YES' % (icase))
    return

for icase in range(Ncases):
    N, M = [int(x) for x in raw_input().split(' ')]

    rows = []
    for i in range(N):
        rows.append([int(x) for x in raw_input().split(' ')])

    solve(icase + 1, rows)
