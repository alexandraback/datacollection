#!/usr/bin/python

# A. 

import sys
import math

vowel = "aeiou"

def isok(s, n):
	count = 0
	for c in s:
		if c in vowel:
			if count >= n:
				return True
			count = 0
		else:
			count += 1
	return count >= n

f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	line = f.readline().split()
	L = line[0]
	n = int(line[1])

	ret = 0
	for i in range(len(L)):
		for j in range(i+n-1, len(L)):
			if isok(L[i:j+1], n):
				ret += 1

	print "Case #%d: %d" % (case, ret)
