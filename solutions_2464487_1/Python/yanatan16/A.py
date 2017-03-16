'''
CodeJam 2013 Round 1A
Problem A: Bullseye
Author: Jon Eisen

This solution uses [pycodejam](http://github.com/yanatan16/pycodejam).
'''
from codejam import CodeJam, parsers
from math import sqrt

def satisfies(r, t, n):
	return t >= (2*r + 1) * n + 2 * n * (n-1)

def solve(ints):
	r, t = ints

	test = lambda n: satisfies(r, t, n)
	assert not test(t/r)
	assert test(1)
	return binary_search(max=t/r, min=1, test=test)

def binary_search(max, min, test):
	if max == min:
		return min
	elif max == min + 1:
		return min if test(min) else max

	x = (max + min) / 2
	# print x, min, max
	if test(x):
		return binary_search(max=max, min=x, test=test)
	else:
		return binary_search(max=x, min=min, test=test)


if __name__ == "__main__":
	CodeJam(parsers.ints, solve).main()