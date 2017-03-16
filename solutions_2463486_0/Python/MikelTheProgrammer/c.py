#if only for the 10 points

from math import sqrt
from sys import stdin, stdout, argv

fin = open(argv[1]) if len(argv) > 1 else stdin
fout = open(argv[2]) if len(argv) > 2 else stdout

def digits(x):
	d = []
	while x:
		d.append(x % 10)
		x //= 10
	return d

def is_palindrome(x):
	d = digits(x)
	return d == d[::-1]

def is_square(x):
	return int(sqrt(x))**2 == x

def is_fas(x):
	return is_square(x) and is_palindrome(x) and is_palindrome(int(sqrt(x)))

N = int(fin.readline())
for case in xrange(1, N + 1):
	a, b = map(int, fin.readline().split())
	t = sum(is_fas(j) for j in xrange(a, b + 1))
	fout.write('Case #%d: %d\n' % (case, t))
