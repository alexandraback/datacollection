#!/usr/bin/env python
import os
import sys
import time
import math

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

def revert_dig(X):
	Y = 0
	while X > 0:
		Y = 10*Y + X%10
		X = int(X/10)
	return Y

def msd(X):
	return int(X/10**int(math.log10(X)))


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):

	N = int(lines[0])
	lines = lines[1:]

	res = 0
	while N > 0:
		if N <= 10:
			res += N
			N    = 0
		else:
			if N%10 == 0:
				N   -= 1
				res += 1

			nd   = int(math.log10(N)+1)
			N1   = N %(10**int((nd+1)/2)) - 1
			N    = N - N1
			res += N1

			Nr = revert_dig(N)
			N2 = Nr%(10**int(nd/2)) -1
			if N2 > 0:
				N = Nr - N2
				res += N2+1

			N   -= 2
			res += 2

	# -------------------------------------------------
  	res = 'Case #%d: %d'%(ncase+1, res)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     













