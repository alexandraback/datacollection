#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
from itertools import chain, combinations
def all_subsets(ss):
	return chain(*map(lambda x: combinations(ss, x), range(0, len(ss)+1)))
def is_full(h, V):
	for i in xrange(1, V + 1):
		if not i in h:
			return [False, i]
	return [True, 0]
	
def solve(C, D, V, arr):
	h  = {}
	for subset in all_subsets(arr):
		h[sum(subset)] = True
	counter = 0
	#print h
	while not is_full(h, V)[0]:
		arr.append(is_full(h, V)[1])
		for subset in all_subsets(arr):
			h[sum(subset)] = True		
		counter += 1
	# for L in range(0, len(arr)+1):
	# 	for subset in itertools.combinations(stuff, L):
	# 		print(subset)
	# for i in xrange(1, V + 1):
		# if i in h:
	#print arr
	return counter
if __name__ == "__main__":
	testcases = input()
	data = [] 
	for caseNr in xrange(1, testcases+1):
		data = raw_input()
		data = data.split(" ")
		C = int(data[0])
		D = int(data[1])
		V = int(data[2])		
		arr = map(lambda x: int(x), raw_input().split(" "))
		print("Case #%i: %s" % (caseNr, solve(C, D, V, arr)))

# 1 10 3 
