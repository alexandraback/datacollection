#!/usr/bin/env python

from sys import stdin

def parse():
	l = map(int,stdin.readline().split())
	return (l[0],l[1],l[2])

def solve(a,b,k):
	if k>=min(a,b):
		return a*b
	return k*(a+b-k) + sum(sum(i&j<k for j in range(b-1, k-1, -1)) for i in range(a-1, k-1, -1))

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(a,b,k) = parse()
		s = solve(a,b,k)
		print "Case #{0}: {1}".format(i+1,s)
