#!/usr/bin/env python
from collections import deque

def main():
	f = open('input.txt', 'r')

	total_T = int(f.readline())

	for T in xrange(1,total_T+1):
		A,B,K = map(long, f.readline().rstrip('\n').split())
		# print A,B,K
		# print basic_solve(xrange(A),xrange(B),K)

		r = basic_solve(xrange(A),xrange(B),K)
		print 'Case #{}: {}'.format(T, r)

def basic_solve(A_iter,B_iter,K):
	c = 0
	for a in A_iter:
		for b in B_iter:
			if a&b < K:
				c+=1
	return c


if __name__ == '__main__':
	main()