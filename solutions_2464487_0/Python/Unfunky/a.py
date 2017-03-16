#!/usr/bin/python -u

import sys, re, math

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 10

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(line1):
  #TODO
  r = int(line1[0])
  t = int(line1[1])
  result = (1 - 2*r + math.sqrt(math.pow((2*r-1),2) + 8*t))/4
  result = int(math.floor(result))
  return result

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




