#!env python3

from codejam import *



@codejam
def solve():
	A, B, K = [int(s) for s in stdin.readline().split()]

	s = 0
	for a in range(A):
		for b in range(B):
			if a & b < K: s += 1

	return s
