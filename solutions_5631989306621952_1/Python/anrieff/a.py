#!/usr/bin/env python

import random

# Contestant: Veselin 'anrieff' Georgiev
# Round: Google Code Jam Qualification 2016
# Task A: The Last Word
# Solution: Greedy on the 'Z's, then on the 'Y's and so on

def findLargest(s): # return a 3-tuple (character, first index, last index)
	minChar = '0'
	mini = 0
	maxi = 0
	for i in xrange(len(s)):
		if s[i] > minChar:
			minChar = s[i]
			mini = i
		if s[i] == minChar:
			maxi = i
	return (minChar, mini, maxi)

def solve(s):
	if s == "":
		return ""
	largest, start, end = findLargest(s)
	out = largest + solve(s[0:start])
	for i in xrange(start + 1, end + 1):
		if s[i] == largest:
			out = s[i] + out
		else:
			out += s[i]
	out += s[end + 1:]
	return out


TC = int(raw_input().strip())

for tc in xrange(1, TC + 1):
	print "Case #%d:" % tc, 
	s = raw_input().strip()
	print solve(s)
	
