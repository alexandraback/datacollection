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

def divisor(N, b=None):
	if b and N % (b+1) == 0: return b+1

	for i in xrange(2, int(ceil(sqrt(N)))+1):
		if N % i == 0:
			return i
	return -1

def do_jacks_magic(jamcoin, middle="0"*30, prefix=""):
	rets = []
	for i in xrange(len(middle)-len(jamcoin), -1, -1):
		middle_nxt = middle[:i] + jamcoin + middle[i+len(jamcoin):]
		jamcoin_nxt = ("1"+prefix)+(middle_nxt)+("1")
		divisors = []
		for b in xrange(2,11):
			B = baseX(jamcoin_nxt, b)
			d = divisor(B, b)
			divisors.append(d)
		if len(divisors) == 9:
			ret = " ".join([jamcoin_nxt, " ".join(map(str, divisors))])
			rets.append(ret)
		else: raise Exception
	return rets

if __name__ == "__main__":
	T = int(sys.stdin.readline())
	for t in xrange(1,T+1):
		print "Case #%d:"%t
		N, J = map(int, raw_input().split(" "))

		j = 0
		m = 30
		while j < J:
			middle = "0"*m
			prefix = "" if (m==30) else ("1"+"0"*(28-m)+"1")
			for nzero in xrange(0, len(middle), 2):
				jamcoin = ("1")+("0"*nzero)+("1")
				res = do_jacks_magic(jamcoin, middle, prefix)
				if (j+len(res)) < J:
					print "\n".join(res)
					j += len(res)
				else:
					print "\n".join(res[:J-j])
					j += J-j
					break
			m -= 2
