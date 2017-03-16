#!/usr/bin/python
# -*- coding: utf-8 -*-
#
#	CodeJam 2013: Round 1A
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

avail = []

def sort(string):
	return "".join(sorted(string))

def genAvail():
	global avail
	s = "2345"
	test = ""
	navail = []
	for ch in s:
		test += ch
		for ch in s:
			test += ch
			for ch in s:
				test += ch
				navail.append(test)		
				test = test[:-1]				
			navail.append(test)		
			test = test[:-1]				
		navail.append(test)		
		test = test[:-1]				
	for elem in navail:
		s = sort(elem)
		if not s in avail:
			avail += [s]
prod = {}

def rem(string, i):
	if i == 0: return string[1:]
	if i == len(string): return string[:-1]
	return string[0:i]  + string[i + 1:]

def genProd():
	global prod
	def getpro(string):
		if len(string) == 0: return 1
		if len(string) == 1: return int(string[0])
		return int(string[0]) * getpro(string[1:])
	
	def getprod(lst):
		ans = [getpro(lst)]
		if len(lst) == 1: return ans
		for i in xrange(len(lst)):
			if lst == '343': print lst, i, rem(lst, i), rem(lst, i) == '33'
			ans += getprod(rem(lst, i))
		return ans
		
	for elem in avail:
		prod[elem] = [1] + getprod(elem)

			
def solve():
	R, N, M, K = filereadInts()
	for r in xrange(R):
		ks = filereadInts()
		for elem in avail:
			if int(max(elem)) > M: continue
			if len(elem) > N: continue
			valid = True
			testlst = prod[elem]
			for e in ks:
				valid = valid and (e in testlst)
				if not valid: break
			if valid:
				file_out.write("%s\n" % elem);
				print elem
				break

def main():
	TC = filereadInt()
	for tt in xrange(1, TC + 1):
		file_out.write("Case #%d:\n" % tt);
		print "Case #%d:" % tt
		solve()
	file_out.close()	
	return 0

if __name__ == '__main__':
	genAvail()
	genProd()
	main()

