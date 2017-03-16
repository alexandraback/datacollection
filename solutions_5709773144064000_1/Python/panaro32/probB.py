#!/usr/bin/env python

from sys import stdin

def parse():
	l = map(float,stdin.readline().split())
	return (l[0],l[1],l[2])

def solve(c,f,x):
	t,r = 0,2
	while c/r+x/(r+f)<x/r:
		t,r = t+c/r,r+f
	return t+x/r

if __name__ == "__main__":
	t = int(stdin.readline())
	for i in range(t):
		(c,f,x) = parse()
		s = solve(c,f,x)
		print "Case #{0}: {1:.7f}".format(i+1,s)
