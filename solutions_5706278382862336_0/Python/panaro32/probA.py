#!/usr/bin/env python

from sys import stdin

def parse():
	l = map(int,stdin.readline().split('/'))
	return (l[0],l[1])

def pow2(n):
	return not (n & (n-1))

def gcd(n,m):
	while n!=0 and m!=0:
		if n>m:
			n %= m
		else:
			m %= n
	return n+m

def solve(p,q):
	d = gcd(p,q)
	p,q = p/d,q/d
	if not pow2(q):
		return -1
	s = 0
	while (2**s)*p < q:
		s +=1
	return s

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(p,q) = parse()
		s = solve(p,q)
		if s == -1:
			print "Case #{0}: {1}".format(i+1,'impossible')
		else:
			print "Case #{0}: {1}".format(i+1,s)
