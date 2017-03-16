#! /usr/bin/python
# -*- coding: utf-8 -*-


import codejammer # https://bitbucket.org/turion/codejammer


def solve_case_small(case):
	A, B, K = map(int, case.split(" "))
	result = 0
	for i in range(A):
		for j in range(B):
			if i & j < K:
				result += 1
	return result

test_in = """5
3 4 2
4 5 2
7 8 5
45 56 35
103 143 88"""
test_solution = """Case #1: 10
Case #2: 16
Case #3: 52
Case #4: 2411
Case #5: 14377"""

#codejammer.set_level(codejammer.DEBUG)
#codejammer.test_jam(test_in, test_solution, solve_case_small)
codejammer.jam("B", solve_case_small)
