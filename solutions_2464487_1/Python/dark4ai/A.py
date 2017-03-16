#!/usr/bin/python
#-*- coding:utf-8 -*-
import sys, re
from math import sqrt, floor

fin = open("A.in", "r")
fout = open("A.out", "w")
count = int(fin.readline())


PI = 3.141592653589793

def f(n, r):
	return 2 * n * n + n * (2 * r - 1)

for test in xrange(1, count + 1):
	r, t = [int(x) for x in fin.readline().split()]
	lb = 1
	rb = int(sqrt(t) * 10)
	while (rb - lb) > 5:
		n = (rb + lb) / 2
		if f(n, r) > t:
			rb = n
		else:
			lb = n
	nmax = -1
	for n in xrange(lb, rb + 1):
		if (f(n, r) <= t):
			nmax = n
	fout.write("Case #{0}: {1}\n".format(test, nmax))