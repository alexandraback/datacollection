#!/usr/bin/env python2

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

def next_cost(r):
	return 2*r + 1

def full_cost(r,k):
	x = 2*k*k + 2*r*k - k

	return x

def solve_sq(a, b, c):
	d = b*b - 4*a*c

	from math import sqrt
	return (-b + sqrt(d))/(2*a)

def binsearch(a, b, foo):
	while a + 1 < b:
		v = (a+b)/2
		if foo(v):
			a = v
		else:
			b = v

	return a

for ct in range(T):
	r, t = read_ints()

	x = solve_sq(2, 2*r-1, -t)

	res = binsearch(1, int(2*x), lambda x: (full_cost(r,x) <= t))

	print 'Case #{}: {}'.format(ct+1, res)

