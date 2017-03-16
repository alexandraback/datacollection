#! /usr/bin/python
# -*- coding: utf-8 -*-


import codejammer # https://bitbucket.org/turion/codejammer

powers = {2**i: i for i in range(41)}


def solve_case(case):
	p, q = map(int, case.split("/"))
	g = gcd(p, q)
	p //= g
	q //= g
	try:
		i = powers[q]
	except KeyError:
		return "impossible"
	b = bin(p)[2:]
	return i - len(b) + first1(b) +1

def first1(s):
	for i, c in enumerate(s):
		if c == "1":
			return i
	else:
		raise ValueError

def gcd(a, b):
	a = int(a)
	b = int(b)
	while b:
		a, b = b, a%b
	return a

test_in = """5
1/2
3/4
1/4
2/23
123/31488"""
test_solution = """Case #1: 1
Case #2: 1
Case #3: 2
Case #4: impossible
Case #5: 8"""

#codejammer.set_level(codejammer.DEBUG)
codejammer.test_jam(test_in, test_solution, solve_case)
codejammer.jam("A", solve_case)
