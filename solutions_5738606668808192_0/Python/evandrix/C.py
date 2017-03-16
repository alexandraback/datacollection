#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
import random
from math import *

def baseX(S, X):
	n, p = 0, 0
	for s in reversed(S):
		n += int(s) * (X**p)
		p += 1
	return n

def divisor(N):
	for i in xrange(2, int(ceil(sqrt(N)))+1):
		if N % i == 0:
			return True, i
	return False, -1

def f(N):
	while True:
		i = random.randint(0,2**(N-2))
		binary = str(bin(i))[2:]
		if len(binary) != N-2:
			binary = "0"*(N-2-len(binary))+binary
		divisors = []
		for b in xrange(2,11):
			B = baseX("1"+binary+"1", b)
			res, d = divisor(B)
			if res: divisors.append(d)
			else: break
		if len(divisors) == 9:
			ret = " ".join(["1"+binary+"1", " ".join(map(str, divisors))])
			return ret

if __name__ == "__main__":
	T = int(sys.stdin.readline())
	for t in xrange(1,T+1):
		print "Case #%d:"%t
		N, J = map(int, raw_input().split(" "))

		# from multiprocessing import Pool
		# p = Pool()
		# print "\n".join(p.map(f, [N]*J))

		j = 0
		while j < J:
			i = random.randint(0,2**(N-2))
			binary = str(bin(i))[2:]
			if len(binary) != N-2:
				binary = "0"*(N-2-len(binary))+binary
			divisors = []
			for b in xrange(2,11):
				B = baseX("1"+binary+"1", b)
				res, d = divisor(B)
				if res: divisors.append(d)
				else: break
			if len(divisors) == 9:
				ret = " ".join(["1"+binary+"1", " ".join(map(str, divisors))])
				print ret
				j += 1
