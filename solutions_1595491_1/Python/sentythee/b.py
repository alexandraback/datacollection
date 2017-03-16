#!/usr/bin/python

from sys import stdin

lines = stdin.readlines()
n = int(lines[0].strip())

for i in range(0, n):
	case = i+1
	line = lines[case]
	nums = [int(x) for x in line.strip().split()]
	
	n = nums[0]
	s = nums[1]
	p = nums[2]
	rest = nums[3:]
	rest.sort()
	rest = rest[::-1]

	used = 0
	out = 0
	
	for g in rest:
		if g % 3 == 0:
			if g/3 >= p:
				out += 1
			elif g/3+1 <= g and g/3+1 >= p and used < s:
				used += 1
				out += 1
		if g % 3 == 2:
			if g/3+1 >= p and g/3+1 <= g:
				out += 1
			elif g/3+2 >= p and g/3+2 <= g and used < s:
				used += 1
				out += 1
		if g % 3 == 1:
			if g/3+1 >= p and g/3+1 <= g:
				out += 1
		

	print 'Case #%d: %d' % (case, out)

