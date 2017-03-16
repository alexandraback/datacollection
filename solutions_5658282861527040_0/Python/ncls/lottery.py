#!/usr/bin/env python

def parse_input():
	t = input()
	test_cases = []
	for i in range(0, t):
		a, b, k = map(int, raw_input().split())
		test_cases.append((a, b, k))
	return test_cases

def solve_test_case(test_case):
	A, B, K = test_case
	possibilities = 0
	for a in range(0, A):
		for b in range(0, B):
			if a & b < K:
				possibilities += 1
	return possibilities

def solve_all_test_cases(test_cases):
	for idx, test_case in enumerate(test_cases):
		print "Case #{}: {}".format(idx + 1, solve_test_case(test_case))

solve_all_test_cases(parse_input())



