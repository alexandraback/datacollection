#!/usr/bin/env python

import sys
import operator
from math import sqrt, floor, ceil
from collections import Counter

class InputFile:
	def __init__(self, fd):
		self.fd = fd
	def readInt(self):
		return int(self.fd.readline())
	def readIntegers(self):
		return tuple([int(x) for x in self.fd.readline().split()])
	def readIntegersList(self):
		return [int(x) for x in self.fd.readline().split()]
	def readString(self):
		return self.fd.readline()[:-1]

def solve(a, motes):
	m.sort()
	azioni_fatte = 0
	azioni_per_finire = []
	
	for i in range(len(motes)):
		s = motes[i]
		mancanti = len(motes)-i
		
		if s >= a:
			#print "Sono ", a, "e non riesco a mangiare", s
			azioni_per_finire.append( azioni_fatte + mancanti )
			
			while s >= a:
				#print " + Sono ", a, "e aumento a", (a+a-1)
				azioni_fatte += 1
				a += a-1
		a += s
		
	azioni_per_finire.append( azioni_fatte )
	
	return min(azioni_per_finire)


inputfile = InputFile(sys.stdin)
T = inputfile.readInt()
for case in range(1,T+1):
	(a, n) = inputfile.readIntegers()
	m = inputfile.readIntegersList()
	
	if n != len(m):
		print "ERRORE"
		sys.exit(1)
	
	if a == 1:
		result = len(m)
	else:
		result = solve(a, m)
	
	print "Case #%d: %d" % (case, result)

