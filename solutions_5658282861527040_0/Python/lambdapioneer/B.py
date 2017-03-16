#!/usr/bin/python
# -*- coding: utf-8 -*-

f = open("B.small","r");

def readInts():
	return map(int, f.readline().split())

caseCnt = int(f.readline())

for caseNr in range(1, caseCnt + 1):
	#go for it
	
	A, B, K = readInts()
	
	sum = 0
	for a in xrange(A):
	  for b in xrange(B):
	    n = a & b
	    if n < K:
	      sum += 1

	print "Case #" + str(caseNr) + ": " + str(sum)
