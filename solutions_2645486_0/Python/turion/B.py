#! /usr/bin/python
# -*- coding: utf-8 -*-

import codejammer # https://bitbucket.org/turion/codejammer
#codejammer.set_level(codejammer.DEBUG)

import collections

def handler(set_):
	cases = []
	iterator = iter(codejammer.set_to_cases(set_))
	while True:
		try:
			cases.append((next(iterator), next(iterator)))
		except StopIteration:
			break
	codejammer.debug(("cases", cases))
	return cases

def solve_case(case):
	E, R, N = map(int, case[0].split(" "))
	codejammer.debug((E, R, N))
	Emin = max(E-R, 0)
	Emax = min(R, E)
	v = list(map(int, case[1].split(" ")))
	vs = sorted(enumerate(v), key=lambda ev: -ev[1])
	emax = [E]*N
	emin = [0]*N
	gain = 0
	for i, vi in vs:
		gain += vi * (emax[i] - emin[i])
		codejammer.debug(("gain w/o corrections", gain))
		if i > 0:
			emin[i-1] = min(Emin, emax[i-1])
			if Emin > emax[i-1]:
				codejammer.debug("sorry, didn't have that much")
				gain -= vi * (Emin - emax[i-1])
				codejammer.debug(("gain corrected", gain))
		if i < N-1:
			emax[i+1] = max(Emax, emin[i+1])
			if Emax < emin[i+1]:
				gain -= vi * (emin[i+1] - Emax)
				codejammer.debug("sorry, need more")
				codejammer.debug(("gain corrected", gain))
		codejammer.debug(("optimised", i, vi))
		codejammer.debug(emax)
		codejammer.debug(emin)
	return gain

test_in = """3
5 2 2
2 1
5 2 2
1 2
3 3 4
4 1 3 5"""

test_solution = """Case #1: 12
Case #2: 12
Case #3: 39"""

codejammer.test_jam(test_in, test_solution, solve_case, handler=handler)
codejammer.jam("B", solve_case, attempt=2, handler=handler)
