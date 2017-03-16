#!/usr/bin/env python

from sys import stdin

def parse():
	l = map(int,stdin.readline().split())
	return (l[0],l[1],l[2])

def solve(a,b,k):
	s = 0
	for i in range(a):
		for j in range(b):
			if i & j < k:
				s += 1
	return s

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(a,b,k) = parse()
		s = solve(a,b,k)
		print "Case #{0}: {1}".format(i+1,s)
