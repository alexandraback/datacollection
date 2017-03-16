#!/usr/bin/env python
import os
import sys
import time
import random

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

def sieveOfEratosthenes(n):
    if n <= 2:
        return []
    sieve = range(3, n, 2)
    top = len(sieve)
    for si in sieve:
        if si:
            bottom = (si*si - 3) // 2
            if bottom >= top:
                break
            sieve[bottom::si] = [0] * -((bottom - top) // si)
    return [2] + [el for el in sieve if el]

def number_in_base_b(N_in_vector_form, base):
  	m = 1
  	x = 0
  	for n in N_in_vector_form:
  		x += n*m
  		m *= base
  	return x


small_primes = sieveOfEratosthenes(50000)
random.seed(33878127)

#---------------------------------------------------------------------
# Main
ncases = int(lines[0])
lines  = lines[1:]
for ncase in xrange(ncases):
  data  = [int(x) for x in lines[0].split()]

  n_digits = data[0]
  n_cases  = data[1]

  if n_digits <= 2:
  	pass
  else:
	solutions = []
  	for nn in xrange(n_cases):
  		while 1:
  			N = [1]+[random.randint(0,1) for k in xrange(n_digits-2)]+[1]  # most significant to lest significant
  			factors = []

  			for b in xrange(2,11):
	  			X = number_in_base_b(N, b)
	  			pmax = X**0.5
	  			factor = 0
	  			for p in small_primes:
	  				if p > pmax:
	  					break
	  				if X%p==0:
	  					factor = p
	  					break
	  			if factor == 0:
	  				break
	  			else:
	  				factors += [factor]

	  		if len(factors) == 9:
	  			solutions += [[number_in_base_b(N, 10)]+factors]
	  			break

	solution = ''
	for sol in solutions:
		text = ''
		for n in sol:
			text = text+' '+str(n)
		solution = solution+'\n%s'%(text[1:])

  # -------------------------------------------------
  res = 'Case #%d: %s'%(ncase+1, solution)
  ofile.write('%s\n'%(res))
  print res

#---------------------------------------------------------------------

ofile.close()

print '\n Run time = ' + str((time.time() - tStart))     
