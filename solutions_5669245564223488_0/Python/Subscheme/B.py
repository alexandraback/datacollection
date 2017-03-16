#!/usr/bin/python

def get(f=int):
	return map(f, raw_input().split())

def memo(f):
	cache = dict()
	def wrap(*args):
		if args not in cache: cache[args] = f(*args)
		return cache[args]
	return wrap

def valid(x):
	last = dict()
	for i, c in enumerate(x):
		if c in last and last[c] < i - 1:
			return False
		last[c] = i
	return True

def change(x):
	last = dict()
	for i, c in enumerate(x):
		if c in last and last[c] < i - 1:
			return None
		last[c] = i
	return (x[0], x[-1], frozenset(x))

from itertools import permutations

MOD = 1000000007

T, = get()

for case in range(1, 1 + T):
	N, = get()
	s = get(change)
	t = 0
	if None not in s:
		for x in permutations(s):
			if valid(x):
				t += 1
	print "Case #%d: %d" % (case, t)

#	s = [(x[0], x[-1], frozenset(x)) for x in get(str) if valid(x)]
#
#	counts = dict()
#	for x in s:
#		if x not in counts: counts[x] = 0
#		counts[x] += 1
#
#	@memo
#	def ways(subset, start_char, end_char):
#		if start == end:
#			return 1 if start_char == end_char else 0
#
#		total = ways(start, end - 1, start_char, end_char) + ways(start + 1, end, start_char, end_char)
#		total %= MOD
#
#		for i in range(start, end):
#			if start_char == s[i][0]:
#				total += ways()