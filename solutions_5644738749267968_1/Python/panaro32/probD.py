#!/usr/bin/env python

from sys import stdin

def parse():
	n = int(stdin.readline())
	l1 = map(float,stdin.readline().split())
	l2 = map(float,stdin.readline().split())
	return (n,l1,l2)

def solve(n,l1,l2):
	l1.sort()
	l2.sort()
	j = 0
	for i in range(n):
		if l1[j]<l2[i]:
			j += 1
	l,r = 0,n-1
	for i in range(n):
		if l1[i]<l2[l]:
			r -= 1
		else:
			l += 1
	return (n-j,l)

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(n,l1,l2) = parse()
		(w,dw) = solve(n,l1,l2)
		print "Case #{0}: {1} {2}".format(i+1,dw,w)
