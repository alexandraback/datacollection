#!/usr/bin/env python

def read_ints():
	return map(int, raw_input().strip().split())

fair = {1, 4, 9, 121, 484}

T, =  read_ints()
for t in range(1, T+1):
	a, b = read_ints()
	print 'Case #{}: {}'.format(t, len(fair.intersection(set(range(a, b+1)))))

