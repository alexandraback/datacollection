#!/usr/bin/env python

import sys

def isPalindrome(x):
	x1 = list(str(x))
	x2 = list(reversed(x1))
	return x1 == x2

def isFairAndSquare(x):
	sqrt_x = int(x ** 0.5)
	return sqrt_x * sqrt_x == x and isPalindrome(sqrt_x) and isPalindrome(x)

numTests = int(raw_input())

for test in xrange(numTests):
	print 'Case #{0}:'.format(test + 1),
	a, b = map(int, raw_input().split())
	l = [i for i in xrange(a, b + 1) if isFairAndSquare(i)]
	print len(l)
