#!env python3

from codejam import *



@codejam
def solve():
	A, B, K = [int(s) for s in stdin.readline().split()]

	s = 0
	for a in range(K, A):
		for b in range(K, B):
			if a & b < K: s += 1

	if K > A or K > B:
		basic = A * B
	else:
		basic = K * (A+B-K)
	return basic + s
