#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 0

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(line1, line2):
	#TODO
	A = int(line1[0])
	B = int(line1[1])
	E_arr = []
	E_arr.append(2 + B)
	pp = float(1)
	for i in range(int(A)):
		pp = pp * float(line2[i])
		E_arr.append(B - i + (1-pp)*(1+B) + A - i - 1)
	debug(E_arr)
	debug(min(E_arr))
	E = min(E_arr)
	return E

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  line2 = infile.readline().strip().split()
  result = handleonecase(line1, line2)
  print "Case #" + str(casenum) + ": " + str(result)




