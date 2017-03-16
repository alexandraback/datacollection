#!/usr/bin/env python
from sys import stdin

T = int(stdin.readline())
	
	

	
for t in xrange(T):
	
	N = int(stdin.readline())
	C = [ map(int, stdin.readline().split(" "))[1:] for i in xrange(N) ]
	
	H = [None for i in xrange(N)] # hierarchy

	def comp_hierachy(i):
		if H[i-1]: return H[i-1]
		H[i-1] = [i]
		if len(C[i-1]) > 0 :
			for j in C[i-1]:
				H[i-1] += comp_hierachy(j)
		return H[i-1]

	diamond = False
	for i in xrange(N):
		val = comp_hierachy(i+1)
		filtered= list(set(val))
		val.sort()
		filtered.sort()
		
		if val != filtered: 
			diamond = True
			break

	if diamond: txt = "Yes"
	else : txt = "No"

	print "Case #%d: %s" % (t+1, txt) 

	
