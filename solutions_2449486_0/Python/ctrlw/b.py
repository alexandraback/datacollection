#!/usr/bin/python
import sys, math, re

def is_possible(field, row_max, col_max):
  for i in range(len(row_max)):
    for j in range(len(col_max)):
      v = field[i][j]
      if v < row_max[i] and v < col_max[j]:
        return False
  return True
  

T = int(sys.stdin.readline())
for t in range(T):
  (rows, cols) = map(int, sys.stdin.readline().strip().split())
  row_max = [0] * rows
  col_max = [0] * cols
  field = []
  # First run: read input, calc max for each row and col
  for i in range(rows):
    row = map(int, sys.stdin.readline().strip().split())
    field += [row]
    for j in range(cols):
      v = row[j]
      if v > row_max[i]:
        row_max[i] = v
      if v > col_max[j]:
        col_max[j] = v
  
  s = "NO"
  if is_possible(field, row_max, col_max):
    s = "YES"
  
  print "Case #%d: %s" % (t + 1, s)
