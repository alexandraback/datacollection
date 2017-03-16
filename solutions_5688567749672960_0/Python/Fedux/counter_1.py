#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys

class InputFile:
	def __init__(self, fd):
		self.fd = fd
	def readInt(self):
		return int(self.fd.readline())
	def readIntegers(self):
		return tuple([int(x) for x in self.fd.readline().split()])
	def readFloats(self):
		return tuple([float(x) for x in self.fd.readline().split()])
	def readIntegersList(self):
		return [int(x) for x in self.fd.readline().split()]
	def readString(self):
		return self.fd.readline()[:-1]

def reverse(x):
	return int(str(x)[::-1])

def timeToNum(x, n):
	#print "From", x, "To", n
	assert(len(str(x)) == len(str(n)))
	sx = str(x)
	sn = str(n)
	l = len(sx)
	if l == 1:
		return n - x
	if x == n:
		return 0
	m = l//2
	a = int(sn[:m][::-1]) - int(sx[:m][::-1])
	b = int(sn[m:]) - int(sx[m:])
	if a == 0:
		return b
	else:
		if n%10 == 0:
			return 1 + timeToNum(x, n-1)
		else:
			return a+b+1

def solve(n):
	i = 1
	x = 1
	while len(str(x)) < len(str(n)):
		# 999
		nnn = int("9"*len(str(x)))
		i += timeToNum(x, nnn)
		x = nnn
		# 1000
		x += 1
		i += 1
	i += timeToNum(x, n)
	return i

inputfile = InputFile(sys.stdin)
T = inputfile.readInt()
for test in range(1,T+1):
	n = inputfile.readInt()
	assert(n > 0)

	result = solve(n)

	print "Case #{test}: {result}".format(test=test, result=result)
