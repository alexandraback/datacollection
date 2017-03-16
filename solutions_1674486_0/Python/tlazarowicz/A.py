#!/usr/bin/env python
import sys

try:
	input_f_name = sys.argv[1]
except:
	print "Provide a file name."
	sys.exit(1)

f = file(input_f_name, 'r')
inp = [ x for x in f.read().split('\n') ][:-1]
num_cases = int(inp.pop(0))

def minus_one(i):
	return i-1

trick = set([])
paths = set([])

def solve_paths(start_inh, cinh, x=0):
	this_paths = set([])
	for i in start_inh:
		path = (x, i)
		if path in paths and path not in this_paths:
			trick.add(path)
			return
		else:
			paths.add(path)
			this_paths.add(path)
			solve_paths(cinh[i], cinh, x)

for i_case in range(num_cases):
	num_classes = int(inp.pop(0))
	cinh = []
	for i in range(num_classes):
		cinh.append(map(minus_one, map(int, inp.pop(0).split(" ")[1:])))
	
	paths = set([])
	trick = set([])
	for k, start_inh in zip(range(len(cinh)), cinh):
		solve_paths(start_inh, cinh, k)
	
	if len(trick) > 0:
		result = "Yes"
	else:
		result = "No"
	print "Case #%d: %s" % (i_case+1, result)
