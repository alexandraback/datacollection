#!/usr/bin/python

# C. Fair and Square

import sys
import math

def isPalindrome(n):
	if len(n) <= 1: 
		return True

	if n[0] == n[-1]:
		return isPalindrome(n[1:-1])
	else:
		return False

def findFirstSquare(A):
	return int(math.ceil(math.sqrt(A)))

f = sys.stdin
T = int(f.readline())

for t in range(1, T+1) :
	A, B = [int(i) for i in f.readline().split()]

	count = 0
	start = findFirstSquare(A)
	for n in range(start, int(math.floor(math.sqrt(B)))+1):
		if isPalindrome(str(n)) and isPalindrome(str(n*n)):
			count += 1

	print "Case #%d: %d" % (t, count)
