# coding: utf-8

import os, sys, re, string
import math,random

def solve(A, v):
	N = len(v)
	if A == 1:
		return N
	v.sort()
	if A > v[-1]:
		return 0
	def f(value, index, operations):
		if index >= N:
			return operations
		if value > v[index]:
			return f(value + v[index], index + 1, operations)
		v1 = operations + (N - index)
		while value <= v[index]:
			value += (value - 1)
			operations += 1
		return min(v1, f(value + v[index], index + 1, operations)) 
	return f(A, 0, 0)

def main():
	T = int(sys.stdin.readline())
	for i in xrange(1, T + 1):
		A, N = map(int, sys.stdin.readline().split())
		v = map(int, sys.stdin.readline().split())
		print 'Case #%d: %d' % (i, solve(A, v))

if __name__ == '__main__':
	main()


