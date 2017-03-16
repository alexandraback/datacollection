#!/usr/bin/env python

import operator
from itertools import combinations_with_replacement as cwr


MD = 5
OD = 30


def genpalls(pat, OD):
	l = len(pat)

	res = []

	for ol in range(l, OD+1):
		for v in cwr(range(l), ol-l):
			count = [0 for x in range(l)]
			for x in v:
				count[x] += 1
			s = ''
			for x in range(l):
				s += '0'*count[x] + pat[x]

			res.append(s)

	return res

def geneven(pat):
#	print pat + pat[::-1]
	pa = genpalls(pat, OD)
	res = []

	for p in pa:
		x = int(p[::-1] + p)
		res.append(x**2)
	
	return res

def genodd(pat):
#	print pat + pat[::-1][1:]
	pa = genpalls(pat[:-1], OD)
	res = []

	for p in pa:
		x = int(p[::-1] + pat[-1] + p)
		res.append(x**2)

	return res

t = reduce(operator.add, [geneven('1'*i) for i in range(1,MD)]) \
		+ reduce(operator.add, [genodd('1'*i) for i in range(1,MD+1)]) \
		+ reduce(operator.add, [genodd('1'*(i-1)+'0') for i in range(2,MD+1)]) \
		+ geneven('2') + genodd('21') + genodd('20') + genodd('12') + genodd('112') +  [4, 9]
	
t.sort()
"""
for n in range(len(t)):
	print t[n]
"""

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

def countless(x):
	if x <= 1:
		return 0
#	print 'countless', x
	a, b = 0, len(t)+1

	while(a+1<b):
		#		print a, b
		v = (a+b+1)/2
		if t[v] < x:
			a = v
		else:
			b = v

	#	print a, b

	return a+1


for tc in range(T):
	a, b = read_ints()
	print 'Case #{}: {}'.format(tc+1, countless(b+1)-countless(a))
