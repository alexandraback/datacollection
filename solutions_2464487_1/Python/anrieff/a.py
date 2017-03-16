#!/usr/bin/python
# # # # # # # # # # #
# Veselin Georgiev
# GCJ 2013 1A
# # # # # # # # # # #

def f(r, n):
	return n * (2*r + 1) + 4 * n * (n - 1) / 2

def solve():
	r, t = map(int, raw_input().split())
	L = 1
	R = 1
	while f(r, R) <= t:
		R *= 2
	while L != R:
		M = (L + R + 1) / 2
		if f(r, M) > t:
			R = M - 1
		else:
			L = M
	return L

def main():
	TC = int(raw_input())
	for i in xrange(1, TC + 1):
		print "Case #%d:" % i, solve()

if __name__ == "__main__":
	main()
