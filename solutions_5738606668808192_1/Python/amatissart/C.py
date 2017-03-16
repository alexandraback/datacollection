# -*- coding: utf-8 -*-

import sys

def binary(n, length):
	s = bin(n)[2:]
	l = len(s)
	return '0'*(length-l)+s

def testdiv(n):
	for i in [2,3,5,7,11,13,17,19,23]:
		if n % i == 0:
			return i
	return None

def solve(N,J):
	n = 2**(N-2)
	j = 0
	for i in xrange(n):
		coin = '1'+binary(i,N-2)+'1'
		divs = []
		for b in xrange(2,11):
			div = testdiv(int(coin,b))
			if div is not None:
				divs.append(div)
			else:
				break
		else:
			print coin, " ".join(map(str,divs))
			j += 1
		if j == J:
			break


filename = sys.argv[1]
with open(filename) as f:
    n_cases = int(f.readline())
    for i in xrange(n_cases):
        N,J = map(int,f.readline().split())
        print 'Case #{}:'.format(i+1)
        solve(N,J)
        
