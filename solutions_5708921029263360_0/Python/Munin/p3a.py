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

def reduce_sol(comb, K, cache = {}):

	comb.sort()

	try:
		comb_tuple = tuple([tuple(x) for x in comb])
		sol = cache[comb_tuple]
		return sol
	except:
		pass

	rAB = {}
	rAC = {}
	rBC = {}

	for case in comb:
		try:
			rAB['%d-%d'%(case[0],case[1])] += 1
		except:
			rAB['%d-%d'%(case[0],case[1])]  = 1
		try:
			rAC['%d-%d'%(case[0],case[2])] += 1
		except:
			rAC['%d-%d'%(case[0],case[2])]  = 1
		try:
			rBC['%d-%d'%(case[1],case[2])] += 1
		except:
			rBC['%d-%d'%(case[1],case[2])]  = 1

	marks = [0 for k in xrange(len(comb))]
	for k,case in enumerate(comb):
		if rAB['%d-%d'%(case[0],case[1])] > K:
			marks[k] = 1
		elif rAC['%d-%d'%(case[0],case[2])] > K:
			marks[k] = 1
		elif rBC['%d-%d'%(case[1],case[2])] > K:
			marks[k] = 1

	if sum(marks) == 0:
		cache[comb_tuple] = comb
		return comb

	best_sol = []
	for k in xrange(len(comb)):
		if marks[k] == 1:
			new_comb = comb[:k]+comb[k+1:]
			new_comb = reduce_sol(new_comb, K)
			if len(new_comb) > len(best_sol):
				best_sol = new_comb

	cache[comb_tuple] = best_sol
	return best_sol


#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
	data = [int(x) for x in lines[0].split()]
	lines = lines[1:]

	A = data[0]
	B = data[1]
	C = data[2]
	K = data[3]

	comb = []
	for ka in xrange(A):
		for kb in xrange(B):
			for kc in xrange(C):
				comb += [[ka,kb,kc]]

	comb = reduce_sol(comb, K)

	solution = len(comb)

	for sol in comb:
		solution = '%s\n'%(solution)
		for x in sol:
			solution += '%d '%(x)

  	# -------------------------------------------------
  	res = 'Case #%d: %s'%(ncase+1, solution)
  	ofile.write('%s\n'%(res))
  	print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
