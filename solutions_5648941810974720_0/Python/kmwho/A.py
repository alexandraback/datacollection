#! /usr/bin/python
# kmwho
# CodeJam 2016  1A

from __future__ import print_function
import numpy as np
import math

def solvecase():
	s = input().strip()
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	count = { c:0 for c in alpha }
	nums  = [ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" ]
	digits = []
	for c in s:
		count[c] += 1
	A  = np.matrix(np.zeros( (26,10) ))
	for r in range(26):
		for c in range(10):
			A[r,c]  = nums[c].count( chr(ord("A") + r ) )
	b  = [ count[c] for c in alpha ]
	X  = (A.I).dot(b)
	digitCount  = [ int(round(d)) for d in X.flat ]
	digits = []
	for d in range(10):
		for x in range(digitCount[d]):
			digits.append( str(d) )
	return "".join(digits)


def solve():
    T  = int(input())
    for t in range(1,T+1):
        res = solvecase()
        print( "Case #" + str(t) + ": " + str(res) )

def main():
	solve()


main()
