#!/usr/bin/env python2

def read_ints():
	return map(int, raw_input().strip().split())

T, = read_ints()

vow = "aeiou"

def count_num(s,n):
	res = 0

	rs = list(enumerate(s))
	rs.reverse()

	t = [ 0 for x in s ]

	prev = 0
	last_n = float('inf')
	for (num,v) in rs:
		if v in vow:
			prev = 0
		else:
			prev += 1
		if prev >= n:
			last_n = num + n

		t[num] = last_n
#		print  num, '->', last_n

	for (a, b) in enumerate(t):
		if b == float('inf'):
			continue
		res += len(s)-b+1
	
	return res


for cur_test in xrange(T):
	s, x = raw_input().strip().split()
	n = int(x)

	res = count_num(s, n)


	print 'Case #{}: {}'.format(cur_test+1, res)
