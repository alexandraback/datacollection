#!/usr/bin/python2
#-*- coding: utf-8 -*-

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  N, M = readarray(int)
  grid = []
  for i in range(N):
    grid.append(readarray(int))
  
  row_max = []
  for i in range(N):
      row_max.append(max(grid[i]))
  col_max = []
  for j in range(M):
    col_max.append(max([grid[i][j] for i in range(N)]))

  good = True
  for i in range(N):
    for j in range(M):
      good &= grid[i][j] >= row_max[i] or grid[i][j] >= col_max[j]
  if good:
    print 'YES'
  else:
    print 'NO'
