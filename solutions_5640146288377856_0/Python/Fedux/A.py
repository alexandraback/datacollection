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

def mossePerFinire(w, c, h):
	"""
	w: larghezza barca
	c: larghezza mare 0..c-1
	h: posizione in cui è colpita
	"""
	assert(w <= c)
	if w == c:
		return w-1
	elif h == 0 or h == c-1:
		return w-1
	else:
		return w

def mossePerScartare(w, c):
	if w > c:
		return 0
	else:
		return c // w

def mossePerTrovare(w, c):
	assert(c >= w)
	d = (c % w) + w
	return (c // w) + mossePerFinire(w, d, w-1)

def solve(r, c, w):
	scar = mossePerScartare(w, c)
	trov = mossePerTrovare(w, c)
	#print "Scarta in", scar
	#print "Trova in ", trov
	return scar * (r-1) + trov


inputfile = InputFile(sys.stdin)
T = inputfile.readInt()
for test in range(1,T+1):
	R, C, W = inputfile.readIntegers()

	result = solve(R, C, W)

	print "Case #{test}: {result}".format(test=test, result=result)
