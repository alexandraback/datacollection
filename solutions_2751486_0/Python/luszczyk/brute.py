#!/usr/bin/env python2

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

vow = "aeiou"

def has_n(s, n):
	prev = 0
	for v in s:
		if v in vow:
			prev = 0
		else:
			prev += 1
		if prev == n:
			return True

def count_num(s,n):
	l = len(s)
	res = 0
	for x in xrange(l):
		for y in xrange(x+1, l+1):
			if has_n(s[x:y], n):
				res += 1
	return res

for cur_test in xrange(T):
	s, x = raw_input().strip().split()
	n = int(x)

	res = count_num(s, n)


	print 'Case #{}: {}'.format(cur_test+1, res)
