#!/usr/bin/python3

t = int(input())
for icase in range(t):
	ssmax, digs = input().split()
	smax = int(ssmax)
	shycount = []
	for d in digs:
		shycount.append(int(d))
	nr_standing = shycount[0]
	nr_needed = 0
	for i in range(1, smax+1):
		c = shycount[i]
		if c > 0 and i > nr_standing:
			nr_needed += i - nr_standing
			nr_standing = i
		nr_standing += c
	print('Case #%d: %d' % (icase+1, nr_needed))
