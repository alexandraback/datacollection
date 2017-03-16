#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 10

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(n,m,lawn):
  row_maxs = [max(i) for i in lawn]
  col_maxs = [max(i) for i in zip(*lawn)]
  for i in range(n):
    for j in range(m):
      if lawn[i][j] == row_maxs[i]: continue
      if lawn[i][j] == col_maxs[j]: continue
      return 'NO'
  return 'YES'

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  n = int(line1[0])
  m = int(line1[1])
  lawn = []
  for i in range(n):
    lawn.append([int(x) for x in infile.readline().strip().split()])
  result = handleonecase(n,m,lawn)
  print "Case #" + str(casenum) + ": " + str(result)




