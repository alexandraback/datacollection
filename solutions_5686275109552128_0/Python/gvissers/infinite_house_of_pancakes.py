#!/usr/bin/python3

def findMin(t, cache):
	if t not in cache:
		m = t[-1]
		if m <= 3:
			cache[t] = m
		else:
			c = m
			for x in range(2, m//2+1):
				t1 = tuple(sorted(t[:-1] + (x, m-x)))
				c = min(c, 1 + findMin(t1, cache))
			cache[t] = c
	return cache[t]

cache = {}
t = int(input())
for icase in range(1, t+1):
	d = int(input())
	ps = tuple(sorted(map(int, input().split())))
	time = findMin(ps, cache)
	print('Case #%d: %d' %(icase, time))
