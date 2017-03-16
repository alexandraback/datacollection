#!/usr/bin/env python
import sys
import itertools

def format_set(s):
	o = ""
	for i in s:
		o = "%s%s " % (o, i)
	return o.strip()

try:
	input_f_name = sys.argv[1]
except:
	print "Provide a file name."
	sys.exit(1)

f = file(input_f_name, 'r')
inp = [ x for x in f.read().split('\n') ][:-1]
num_cases = int(inp.pop(0))


for i_case in range(num_cases):
	case_input = set(map(int, inp.pop(0).split(" ")[1:]))
	set_one = set([])
	set_two = set([])
	
	d = {}
	poss = set([])
	
	b = False
	for r in range(1, len(case_input)+1):
		if b:
			break
		for comb in itertools.combinations(case_input, r):
			s = sum(comb)
			if s in poss and comb != d[s]:
				set_one = d[s]
				set_two = comb
				b = True
			else:
				poss.add(s)
				d[s] = comb
	
	
	i = i_case + 1
	print "Case #%d:" % i
	
	if len(set_one) > 0 and len(set_two) > 0:
		print "%s" % format_set(set_one)
		print "%s" % format_set(set_two)
	else:
		print "Impossible"
