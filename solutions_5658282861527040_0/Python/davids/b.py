from __future__ import division
from collections import defaultdict
import sys, os

	
def do_case(a,b,k):
	counts = defaultdict(int)
	if a > b:
		t = b
		b = a
		a = t
	
	for i in range(a):
		for j in range(b):
			counts[i&j] += 1
	total = 0
	for i in range(k):
		total += counts[i]
	
	return total
	
f = open(sys.argv[1], 'r')
out = open(sys.argv[2], 'w')

num_cases = int(f.readline())
for i in range(1,num_cases+1):
	a,b,k = map(int, f.readline().split())  
	res = do_case(a, b, k)
	print "Case #%d:" % (i), res
	out.write("Case #%d: %s\n" % (i, res))

	
	