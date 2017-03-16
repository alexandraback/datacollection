#!/usr/bin/env python2

nc = int(raw_input())
for c in xrange(nc):
	tmp = map(int,raw_input().split())
	n = tmp[0]
	s = tmp[1]
	p = tmp[2]
	tp = tmp[3:]

	cnt = 0
	for t in tp:
		if t == 0:
			if p == 0:
				cnt += 1
		elif (t-p)/2.0-p >= -1.0:
			cnt += 1
		elif s > 0 and ((t-p)/2.0)-p >= -2.0:
			s -= 1
			cnt += 1

	print "Case #%i: %i" % (c+1, cnt)
