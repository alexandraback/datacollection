#!/usr/bin/python

import pdb

def paly(num):
	s = str(num)
	i = 0
	j = len(s) - 1
	while i < j:
		if s[i] != s[j]: return False
		i += 1
		j -= 1
	return True

"""current string, remaining to be done, num nonzero chars"""

def f(s, left, nonzero, ret):
	if left == 0:
		ret.append(s)
		return
	f(s + "0", left - 1, nonzero, ret)
	if nonzero < 5:
		f(s + "1", left - 1, nonzero + 1, ret)
		if left == 1:
			f(s + "2", left - 1, nonzero + 1, ret)

def halfgenerator():
	for i in xrange(1, 10000):
		yield i
	for L in xrange(5, 26):
		# generate "1[01]*[012]", of length L, with no more than 5 non-zero chars:
		#pdb.set_trace()
		ret = []
		f("1", L - 1, 1, ret)
		for res in ret:
			yield res
		#M = L - 2
		#for mask in xrange(0, 2**M):
			#for lastDig in xrange(0, 3):
				#candidate = "1"
				#for i in xrange(M - 1, -1, -1):
					#candidate += str((mask >> i) & 1)
				#candidate += str(lastDig)
				#yield candidate
		# generate "200...0", "200...1" of length L
		yield 2 * 10**(L - 1)
		yield 2 * 10**(L - 1) + 1

def reverse(s):
	return "".join([s[i] for i in xrange(len(s) - 1, -1, -1)])

"""find the first index i, such that arr[i] >= x"""
def lowerBound(arr, x):
	l = 0
	r = len(arr)
	while l != r:
		m = (l + r) / 2
		if arr[m] < x:
			l = m + 1
		else:
			r = m
	return l

allPalys = []

for half in halfgenerator():
	s = str(half)
	for i in [s + reverse(s)[1:], s + reverse(s)]:
		j = int(i)**2
		if paly(j) and j <= 10**100:
			allPalys.append(j)

allPalys.sort()


T = int(raw_input())

for tc in xrange(1, T + 1):
	a, b = map(long, raw_input().strip().split())
	print "Case #%d: %d" % (tc, lowerBound(allPalys, b + 1) - lowerBound(allPalys, a))
