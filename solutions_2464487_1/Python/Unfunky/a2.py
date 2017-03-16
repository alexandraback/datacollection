#!/usr/bin/python -u

import sys, re, math

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 10

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def cost_of_n_rings(r, n):
  return 2*r*n + 2*n*n - n

def handleonecase(line1):
  r = long(line1[0])
  t = long(line1[1])
  n_min = 1
  n_max = (1+2*t / 4)
  while n_min != n_max:
    n_mid = int((n_min + n_max + 1) / 2)
    if(cost_of_n_rings(r,n_mid) > t):
      n_max = n_mid - 1
      continue
    else:
      n_min = n_mid
      continue
  n = n_min
  return n

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  result = handleonecase(line1)
  print "Case #" + str(casenum) + ": " + str(result)




