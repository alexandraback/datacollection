#!/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import sys
from decimal import *
import itertools as it
from math import sqrt
from math import floor
from math import ceil
from math import log
from math import log10
import time
import random
import re
import string

inf = float('inf')

def solve(C, J):

	n = len(C)
	Csum = 0
	Jsum = 0

	Carray = list(C)
	Jarray = list(J)

	for i,c,j in zip(range(n),C,J):

		if Csum == Jsum:
			if c == '?' and j == '?':
				Carray[i] = '0'
				Jarray[i] = '0'
			elif c == '?':
				Carray[i] = j
				Csum += int(j) * 10**(n-i-1)
			elif j == '?':
				Jarray[i] = c
				Jsum += int(c) * 10**(n-i-1)

		elif Csum > Jsum:
			if c == '?':
				Carray[i] = '0'
			if j == '?':
				Jarray[i] = '9'
				Jsum += 9 * 10**(n-i-1)

		else:
			if c == '?':
				Carray[i] = '9'
				Csum += 9 * 10**(n-i-1)
			if j == '?':
				Jarray[i] = '0'

		if c != '?':
			Csum += int(c) * 10**(n-i-1)
		if j != '?':
			Jsum += int(j) * 10**(n-i-1)

	return '{} {}'.format(''.join(Carray), ''.join(Jarray))

def main():
	infile = sys.argv[1]
	f = open(infile,'r')

	T = int(next_line(f))
	for t in range(T):
	    C, J = next_line(f).split()
	    print 'Case #{}: {}'.format(t+1, solve(C, J))

	f.close()

def next_line(f):
    return f.readline().strip()

main()
