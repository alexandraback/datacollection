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

import numpy as np

inf = float('inf')

def solve(B, M):
	num_entries = (B*(B-1)) / 2

	for i in range(2**num_entries):
		A = np.zeros((B,B), dtype=int)
		k = i
		row = 0
		entry = 1
		for which_entry in range(num_entries):
			A.itemset((row,entry),k % 2)
			k /= 2
			entry += 1
			if entry == B:
				row += 1
				entry = row + 1

		num_paths = 0
		for i in range(1,B):
			num_paths += np.linalg.matrix_power(A,i)[0][B-1]

		if num_paths == M:
			# print np.linalg.matrix_power(A,1)
			# print np.linalg.matrix_power(A,2)
			# print np.linalg.matrix_power(A,3)
			# print np.linalg.matrix_power(A,4)
			# print np.linalg.matrix_power(A,5)
			return 'POSSIBLE\n' + matrix_to_string(A)

	return 'IMPOSSIBLE'

def sum_of_matrix_powers(A, p):
	m,n = A.shape
	assert m == n
	assert p >= 0

	I = np.identity(n, dtype=int)
	return _sum_of_matrix_powers_recursive(A,p) + I

def _sum_of_matrix_powers_recursive(A, p):
	m,n = A.shape
	I = np.identity(n, dtype=int)

	if p == 1:
		return A

	sqrtAn = np.linalg.matrix_power(A, p/2)
	B = _sum_of_matrix_powers_recursive(A, p/2) * (I + sqrtAn)

	return B if p%2 == 0 else B + sqrtAn**2

def matrix_to_string(A):
	out = []

	for row in np.ndarray.tolist(A):
		out.append(''.join(map(str,row)))

	return '\n'.join(out)

def main():
	infile = sys.argv[1]
	f = open(infile,'r')

	T = int(next_line(f))
	for t in range(T):
	    B,M = map(int, next_line(f).split())
	    print 'Case #{}: {}'.format(t+1, solve(B,M))

	f.close()

def next_line(f):
    return f.readline().strip()

main()
