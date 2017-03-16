#!/usr/bin/env python
import os
import sys
import time

tStart = time.time()

#---------------------------------------------------------------------

ifilename = 'input.in'
ofilename = 'results.out'

args = sys.argv
if len(args) > 1:
  ifilename = args[1]
if len(args) > 2:
  ofilename = args[2]

#---------------------------------------------------------------------
 
ifile = open(ifilename,'r')
data  = ifile.read()
ifile.close()
lines = data.splitlines()

ofile = open(ofilename, 'w')

#---------------------------------------------------------------------
# Functions


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data  = [int(x) for x in lines[0].split()]
  lines = lines[1:]

  K = data[0]
  C = data[1]
  S = data[2]

  if C == 1 and S < K:
   	solution = 'IMPOSSIBLE'
  elif C == 1 and S >= K:
   	solution = ''
   	for k in xrange(1,K+1):
   		solution += '%d '%(k)
  elif K == 1:
   	solution = '1'
  else:
  	nums = []
  	pos  = range(K)
  	while len(pos) > 0:
  		p    = 0
  		comp = 1
		for k in xrange(C):
			if len(pos) > 0:
				p   += pos[0]*comp
				pos  = pos[1:]
			comp *= K
		nums += [p+1]
	if len(nums) <= S:
		nums.sort()
	   	solution = ''
	   	for x in nums:
	   		solution += '%d '%(x)
	else:
	   	solution = 'IMPOSSIBLE'

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
