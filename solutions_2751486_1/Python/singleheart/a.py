#!/usr/bin/python

# A. 

import sys
import math

vowel = "aeiou"

f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	line = f.readline().split()
	L = line[0]
	n = int(line[1])

	count = 0
	for i in range(0, n):
		if L[i] in vowel:
			count = 0
		else:
			count += 1

	ret = 0
	for i in range(n-1, len(L)):
		if L[i] in vowel:
			count = 0
			continue
		else:
			count += 1
		if count >= n:
			ret += i-n+1
			ret += len(L)-i

	print "Case #%d: %d" % (case, ret)
