#!/usr/bin/python3
import sys

f = open("B-small-attempt0.in")
g = open("B-small-attempt0.out", "w")

T = int(f.readline())
    
for caseNo in range(1, T+1):
    N, M = map(int, f.readline().strip().split())
    field = []
    rowMax = []
    for i in range(N):
        row = list(map(int, f.readline().strip().split()))
        field.append(row)
        rowMax.append(max(row))
    colMax = []
    for j in range(M):
        col = [field[i][j] for i in range(N)]
        colMax.append(max(col))
    ans = all([(field[i][j] >= rowMax[i]) or (field[i][j] >= colMax[j]) for i in range(N) for j in range(M)])
    print("Case #{0}: {1}".format(caseNo, "YES" if ans else "NO"), file=g)
g.close()
