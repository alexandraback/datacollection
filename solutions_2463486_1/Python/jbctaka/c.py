#!python
# -*- coding: utf-8 -*-

import sys

def is_p(num):
	s = str(num)
	l = len(s)
	for i in range(l / 2):
		if s[i] != s[l - 1 - i]: return False
	return True


nums = set()
for i in range(1, 100000):
    s = str(i)
    n = int(s[:-1] + s[::-1])
    m = int(s + s[::-1])
    if is_p(n * n): nums.add(n * n)
    if is_p(m * m): nums.add(m * m)

T = int(sys.stdin.readline().strip())
for index in range(1, T + 1):
	Rng = [int(x) for x in sys.stdin.readline().split()]
	print "Case #%d: %d" % (index, len([x for x in nums if Rng[0] <= x <= Rng[1]]))
