# coding: utf-8

import os, sys, re, string
import math,random

def solve(r, c, w):
	if r > 1:
		return (r - 1) * (c / w) + solve(1, c, w)
	if c == w or w == 1:
		return r * c
	if c > 2 * w:
		return 1 + solve(r, c - w, w)
	return w + 1

def main():
	t = int(sys.stdin.readline().strip())
	for x in xrange(t):
		r, c, w = map(int, sys.stdin.readline().split(' '))
		print "Case #{0}: {1}".format(x + 1, solve(r, c, w))

if __name__ == '__main__':
	main()


