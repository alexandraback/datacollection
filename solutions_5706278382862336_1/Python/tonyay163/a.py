#!/usr/bin/python

from sys import stdin
import math
from fractions import *

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def elf(a, b):
	if b != 0 and ((b & (b - 1)) == 0):
		if a == 1:
			return int(math.log(b, 2))
		else:
			f = Fraction(a, b) * 2
			if f > 1:
				f = f - 1
				result = elf(f.numerator, f.denominator)
				if result == "impossible":
					return "impossible"
				else:
					return 1
			else:
				result = elf(f.numerator, f.denominator)
				if result == "imposible":
					return "impossible"
				else:
					return 1 + result
	else:
		return "impossible"

lines = stdin.read().splitlines()
num_cases = int(lines[0])
lines = lines[1:]
for case in xrange(num_cases):
	line = lines[case].split("/")
	p = int(line[0])
	q = int(line[1])
	d = gcd(p, q)
	p = p / d
	q = q / d
	print "Case #{0}: {1}".format(case + 1, elf(p, q))