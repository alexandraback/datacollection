import sys
from fractions import Fraction
import math

num_cases = int(sys.stdin.readline().strip())

# http://stackoverflow.com/questions/15352593/how-to-check-if-a-number-is-a-power-of-base-b
def isPower (num, base):
    if base == 1 and num != 1: return False
    if base == 1 and num == 1: return True
    if base == 0 and num != 1: return False
    power = int (math.log (num, base) + 0.5)
    return base ** power == num
	
def helper(current, target, gens):
	# print "helper cur %s tar %s" % (current, target)
	if gens > 40:
		return -1
	if current <= target:
		return gens
	return helper(current / 2, target, gens + 1)
	
def solve(f):
	return helper(Fraction(1, 1), f, 0)
	
for i in range(num_cases):
	#p, q = map(int, sys.stdin.readline().strip().split('/'))
	f = Fraction(sys.stdin.readline().strip())
	if not isPower(f.denominator, 2):
		result = "impossible"
	else:
		result = solve(f)
		if result == -1:
			result = "impossible"
	print "Case #%s: %s" % (i+1, result)
