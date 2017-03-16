#!/usr/bin/env python
# -*- coding: utf-8 -*-
from math import *

def solve(A, B):
	global ret
	lbound, ubound = int(ceil(sqrt(A))), int(floor(sqrt(B)))
	lrange, urange = len(str(lbound)), len(str(ubound))
	ret = 0
	for i in xrange(lrange, urange+1, 1):
		def gp(num, i, j):
			global ret
			if i > j:
				num1 = int("".join(num))
				if num1 >= lbound and num1 <= ubound:
					num1 = str(num1*num1)
					i, j = 0, len(num1)-1
					while i < j: 
						if num1[i] != num1[j]: break
						i += 1
						j -= 1
					if i >= j: ret += 1
			else:
				for k in xrange(10):
					num[i], num[j] = str(k), str(k)
					gp(num, i+1, j-1)

		num = ['0' for k in xrange(i)]
		gp(num, 0, len(num)-1)
	return ret

if __name__ == "__main__":
	T = int(raw_input())
	for i in xrange(1, T+1, 1):
		A, B = map(int, raw_input().split())
		print "Case #%d: %d" % (i, solve(A, B))