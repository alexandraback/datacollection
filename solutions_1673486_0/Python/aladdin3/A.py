#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#	CodeJam 2012: Round-1A
#	Author: Mahmoud Aladdin (Platter)
# 

file_in = open("A.in", 'r')
file_out = open("A.out", "w")
# ======================================
filereadLine = lambda: file_in.readline().strip()
filereadInt = lambda: int(file_in.readline().strip())
filereadInts = lambda: map(int, file_in.readline().strip().split(' '))
filereadFloats = lambda: map(float, file_in.readline().strip().split(' '))
# ======================================
import math
# ======================================

def mul(pA): 
	ans = 1.0
	for a in pA: ans *= a
	return ans
	
A, B = 0, 0	
def continue_(pA, esc):
	suc = mul(pA)
	re = B - len(pA) + 1 + esc
	return suc * re + ((1 - suc) * (re + B + 1))



def main():
	global A,B
	T = filereadInt()
	for tt in xrange(1, T + 1):
		A, B = filereadInts()
		pA = filereadFloats()
		min_case = B + 2
		for a in xrange(A, -1, -1):
			min_case = min(min_case,continue_(pA[:a], A - a))
		print min_case
		file_out.write('Case #{}: {}\n'.format(tt, min_case))
	print "Program Terminatted"
	return 0
	
if __name__ == '__main__':
	main()
