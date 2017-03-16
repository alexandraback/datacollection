#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 0

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(line1,line2):
  E = int(line1[0])
  R = int(line1[1])
  N = int(line1[2])
  V = [0] # dummy v
  min_after = [0]
  max_after = [E]
  for vi in line2:
    V.append(int(vi))
    min_after.append(0)
    max_after.append(E)
  gain = 0
  while True:
    debug('min_after: ' + str(min_after))
    debug('max_after: ' + str(max_after))
    if(len(V) == 1): break
    # find maximum of V
    i = V.index(max(V))
    debug(str(i) + ": " + str(V[i]), 3)
    # spend what we can on that, and keep track of 'gain'
    spend = max_after[i] - min_after[i]
    debug('spend =' + str(spend))
    gain = gain + spend * V[i]
    debug('gain  =' + str(spend))
    # update min_after of elements before
    update_min_after(V, min_after, max_after, i, R)
    # update max_after of elements after
    update_max_after(V, min_after, max_after, i, R)
    # remove elements
    V = V[:i] + V[i+1:]
    min_after = min_after[:i] + min_after[i+1:]
    max_after = max_after[:i] + max_after[i+1:]
  return gain

def update_min_after(V, min_after, max_after, i, R):
  to = max_after[i] - R
  while True:
    if(i==0): return
    i = i - 1
    if(min_after[i] >= to): return
    min_after[i] = to
    to = to - R

def update_max_after(V, min_after, max_after, i, R):
  to = min_after[i] + R
  while True:
    if(i+1 >= len(V)): return
    i = i + 1
    if(max_after[i] <= to): return
    max_after[i] = to
    to = to + R

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  line2 = infile.readline().strip().split()
  result = handleonecase(line1,line2)
  print "Case #" + str(casenum) + ": " + str(result)




