from sys import stdin
from fractions import Fraction
from math import *

def printAnswer(caseIndex, answer):
	print("Case #", caseIndex+1, ": ", answer, sep='')

T = int(input())
for t in range(T):
	partElf = Fraction(input())

	denPower = int(log(partElf.denominator, 2))
	if (2 ** denPower == partElf.denominator):
		numPower = int(log(partElf.numerator, 2))
		printAnswer(t, denPower - numPower)
	else:
		printAnswer(t, "impossible")