#!/usr/bin/env python
# -*- coding: UTF-8 -*-

# Fai la divisione con la virgola
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

def solve(a, b, k):
	count = 0
	for aa in xrange(a):
		for bb in xrange(b):
			if aa & bb < k:
				count += 1
	return count


inputfile = InputFile(sys.stdin)
T = inputfile.readInt()
for test in range(1,T+1):
	(a, b, k) = inputfile.readIntegers()
	(a, b) = (min(a, b), max(a, b))
	result = solve(a, b, k)
	
	print "Case #{test}: {result}".format(test=test, result=result)

