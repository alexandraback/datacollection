#! /usr/bin/python

from fractions import Fraction

n = int(input())
for i in range(0, n):
	f = Fraction(input())
	if (f.denominator & (f.denominator - 1)):
		print("Case #{}: impossible".format(i + 1))
		continue
	for j in range(1, 41):
		if f >= Fraction(1, 2**j):
			print("Case #{}: {}".format(i + 1, j))
			break
