#!/usr/bin/env python 

from fractions import Fraction

gens = [2**n for n in range(41)]

def elf(n,d):
	# First, conv to LCD
	# skipped for small setsmall setc
	r = Fraction(n,d)
	n,d = r.numerator,r.denominator
	if r.denominator not in gens: return 'impossible'
	gen = 1
	while gen <= 40:
		if d < 1: return 'impossible'
		if Fraction(n,d) >= Fraction(1,2): return gen
		gen += 1
		d /=2
	return 'impossible'

		
		
	


if __name__ == "__main__":
	import sys
	testcases = int(sys.stdin.readline())
	for casenum in range(testcases):
		n,d = map(int,sys.stdin.readline().split('/'))
		print "Case #%s:" % (casenum+1,),elf(n,d)
