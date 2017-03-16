#!/usr/bin/python2.7
from itertools import combinations

def UpdateValues(data):
	values = data[:]
	for i in xrange(2, len(data)):
		for c in combinations(data, i):
			values.append(sum(c))
	values.append(sum(data))
	return values


for case in range(input()):
	C, D, V = map(int, raw_input().split())
	data = map(int, raw_input().split())

	values = UpdateValues(data)

	for i in xrange(1, V+1):
		if (i not in values):
#			values.sort()
#			print i, values
			data.append(i)
			values = UpdateValues(data)


	print 'Case #%s: %s' % ((case + 1), len(data)-D)

