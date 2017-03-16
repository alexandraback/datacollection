#!/usr/bin/env pypy

import sys
from collections import defaultdict

def readline():
	s = raw_input().strip()
	while s == "":
		s = raw_input().strip()
	return s

def readvals():
	return map(int, readline().split())

def generate_palindromes_of_length(digits):
	if digits == 1:
		for i in range(0, 10):
			yield i
	elif digits == 2:
		for i in range(1, 10):
			yield i * 11
	elif digits > 2:
		rest = tuple(map(str, generate_palindromes_of_length(digits - 2)))
		for c in "123456789":
			for p in rest:
				yield int(c + p + c)

def is_palindrome(n):
	s = str(n)
	X = len(s)
	for i in range(X // 2):
		if s[i] != s[X-i-1]:
			return False
	return True

def generate_palindromes():
	digits = 1
	while True:
		for x in generate_palindromes_of_length(digits):
			yield x
		digits += 1

def generate_fairsquare(limit):
	for p in generate_palindromes():
		sq = p * p
		if sq > limit:
			break
		if is_palindrome(sq):
			yield sq

# precompute palindromes




if __name__ == "__main__":
	sys.stderr.write("Precalculating...\n")
	palindromes = tuple(generate_fairsquare(10**14))
	sys.stderr.write("Done!\n")

	def count_fair_square(limit):
		"""
		Returns a count of how many fair squares are <= limit
		"""
		low, high = 0, len(palindromes) - 1
		while low <= high:
			mid = (low + high) // 2
			if palindromes[mid] <= limit:
				low = mid + 1
			else:
				high = mid - 1
		return high + 1

	def solve():
		low, high = readvals()
		return count_fair_square(high) - count_fair_square(low - 1)

	N = int(readline())
	for i in range(N):
		sol = solve()
		print("Case #{0}: {1}".format(i+1, sol))
