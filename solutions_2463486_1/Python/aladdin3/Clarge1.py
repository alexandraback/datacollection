#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#	CodeJam 2013: Qualification Round
#	Author: Mahmoud Aladdin (aladdin3)
#

file_in = open("C.in", 'r')
file_out = open("C.out", "w")
# ======================================
filereadLine = lambda: file_in.readline().strip()
filereadInt = lambda: int(file_in.readline().strip())
filereadInts = lambda: map(int, file_in.readline().strip().split(' '))
# ======================================
import math
# ======================================

def isPalin(x):
	s, ox = 0, x
	while (x > 0):
		r = x % 10
		x /= 10
		s = s * 10 + r
	return s == ox

def genAnswer():
	lst = []
	for i in xrange(1, 10 ** 7 + 1):
		if(isPalin(i) and isPalin(i * i)):
			lst.append(i * i)
	return lst	

def main():
	lst = genAnswer()
	print "Done part A"
	n = filereadInt()
	for tt in xrange(1, n + 1):
		ans = 0
		a, b = filereadInts()
		for elem in lst:
			if elem >= a and elem <= b:
				ans += 1
			
		file_out.write("Case #%d: %d\n" % (tt, ans))
		#print "Case #%d: %d" % (tt, ans)
	file_out.close()	
	return 0
if __name__ == '__main__':
	main()

