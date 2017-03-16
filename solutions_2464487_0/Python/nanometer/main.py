#!/usr/bin/env python

def check(r, t, p):
	return (2 * p * r + (2 * p - 1) * p) <= t

def solve():
	r, t = raw_input().split(' ')
	r = int(r)
	t = int(t)
	low = 0
	upp = pow(10, 30)
	while low < upp:
		mid = (low + upp + 1) // 2
		if check(r, t, mid): low = mid
		else: upp = mid - 1
	print low

if __name__ == '__main__':
	test_cases = int(raw_input())
	for t in range(1, test_cases + 1):
		print 'Case #%d:' % t, 
		solve()