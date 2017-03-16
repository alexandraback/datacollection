#!/usr/bin/env python3
# -*- coding: utf-8 -*-

numbers = [-1]

f = open('C-numbers.txt')
for l in f: numbers.append(int(l))
f.close()

def max_not_greater(p):
	s = 0
	e = len(numbers)
	while True:
		h = (s + e) // 2
		if numbers[h] <= p < numbers[h + 1]:
			return h
		elif numbers[h] > p: e = h
		elif p >= numbers[h + 1]: s = h

def min_not_lower(p):
	s = 0
	e = len(numbers)
	while True:
		h = (s + e) // 2
		if numbers[h - 1] < p <= numbers[h]:
			return h
		elif numbers[h - 1] >= p: e = h
		elif p > numbers[h]: s = h

def single_test():
	A, B = map(int, input().split())
	aa = min_not_lower(A)
	bb = max_not_greater(B)
	return bb - aa + 1

T = int(input())
for i in range(T):
	print("Case #%d: %d" % (i + 1, single_test()))
