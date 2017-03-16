#!/usr/bin/python

import sys
import itertools

def get_subsets(S,m):
	return set(itertools.combinations(S, m))


inp = sys.stdin

T = int(inp.readline())

j = 0
while j < T:
	j+=1
	print "Case #"+str(j)+": "
	inplist = inp.readline().split()
	num = int(inplist[0])
	
	p_ints = [int(x) for x in inplist[1:]]
	
	sum_dict = {}
	found = False
	for i in range(len(p_ints)):
		p_iter = get_subsets(p_ints,i+1)
		if found:
			print ""
			break
		for x in p_iter:
			sump = sum(x)
			try:
				y = sum_dict[sump]
#				print "found"
#				print sum_dict[sump]
#				print x
				for a in sum_dict[sump]:
					print a,
					print " ",
				print ""
				for a in x:
					print a,
					print " ",
				found = True 
				break
			except:
				sum_dict[sump] = x
			if found:
				break
	if not found:
		print "Impossible"

