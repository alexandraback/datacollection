#!/usr/bin/env python

def is_palindrome(a):
	a = str(a)
	l = len(a)
	for i in xrange(l/2):
		if a[i] != a[l-1-i]:
			return False
	return True

ans = [1,3,2]

def test(s):
	n = int("".join(s))
	if is_palindrome(n*n):
		ans.append(n)

def rec_gen(s, l, i, ones):
	if i*2 == l:
		test(s)
		return
	if i*2 == l-1:
		s[i] = '0'
		test(s)
		s[i] = '1'
		test(s)
		s[i] = '2'
		test(s)
		return
	s[i] = '0'
	s[l-1-i] = '0'
	rec_gen(s,l,i+1, ones)
	if ones < 4:
		s[i] = '1'
		s[l-1-i] = '1'
		rec_gen(s,l,i+1, ones+1)

for l in xrange(2,52):
	s = ['1']*l
	rec_gen(s,l,1,1)

	s = ['0']*l
	s[0] = '2'
	s[l-1] = '2'
	test(s)
	if l%2 == 1:
		s[l/2] = '1'
		test(s)

	l += 1

ans.sort()

#for i in xrange(411):
#	print ans[i]#, ans[i]*ans[i]
#print ans

import sys

T = int(sys.stdin.readline())
for t in xrange(T):
	A,B = [int(x) for x in sys.stdin.readline().split()]
	c = 0
	for v in ans:
		if v*v >= A and v*v <= B:
			c += 1
	print "Case #%d: %d" % (t+1, c)