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
def get_sol(v):

	if len(v) == 1:
		if v[0] == 1:
			return 0
		else:
			return 1
	else:
		if v[-1] == 1:
			return get_sol(v[:-1])
		else:
			return 1+get_sol([(x+1)%2 for x in v])

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data  = [x for x in lines[0].split()]
  lines = lines[1:]
  data  = [int(data[0][k]=='+') for k in xrange(len(data[0]))]

  solution = get_sol(data)

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
