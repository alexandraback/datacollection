#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#	CodeJam 2013: Round 1A
#	Author: Mahmoud Aladdin (aladdin3)
#

file_in = open("A.in", 'r')
file_out = open("A.out", "w")
# ======================================
filereadLine = lambda: file_in.readline().strip()
filereadInt = lambda: int(file_in.readline().strip())
filereadInts = lambda: map(int, file_in.readline().strip().split(' '))
# ======================================
import math
# ======================================

def can(a, d, n, t):
	s = n * ((2 * a) + ((n - 1) * d))
	#print n, s, 2 * t, s <= (2 * t)
	return s <= (2 * t)

def binarySearch(a, d, mn, mx, t):
	ans = 0
	#print mn, mx
	while mx >= mn:
		md = (mx + mn) >> 1
		if(can(a, d, md, t)):
			ans = md
			mn = md + 1
		else:
			mx = md - 1
	return ans
	

def solve(r, t):
	a = (2 * (r + 1)) - 1
	d = 4
	n = 2
	while True:
		s = (n * ((2 * a) + ((n - 1) * d))) >> 1
		if s > t:
			return binarySearch(a, d, n >> 1, n, t)
		n = n << 1
	

def main():
	
	TC = filereadInt()
	for tt in xrange(1, TC + 1):
		r, t = filereadInts()
		ans = solve(r, t)
		file_out.write("Case #%d: %d\n" % (tt, ans))
		print "Case #%d: %d" % (tt, ans)
	file_out.close()	
	return 0
if __name__ == '__main__':
	main()

