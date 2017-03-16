#!/usr/bin/env python

import sys

vals = {}
# store 

for i in xrange(0, 11):
	for j in xrange(0, 11):
		if abs(i - j) > 2:
			continue
		for k in xrange(0, 11):
			if abs(i - k) > 2 or abs(k - j) > 2:
				continue
			surprising = abs(i - k) == 2 or abs(k - j) == 2 or abs(i - j) == 2
			score = i + j + k
			highest = max(i, j, k)
			if score not in vals:
				vals[score] = (-1, -1)
			if surprising:
				if highest > vals[score][1]:
					vals[score] = (vals[score][0], highest)
			else:
				if highest > vals[score][0]:
					vals[score] = (highest, vals[score][1])

case_no = 0
for line in sys.stdin:
	line = [int(val) for val in line.strip().split()]
	if len(line) == 1:
		continue
	case_no += 1
	N = line[0]
	S = line[1]
	p = line[2]
	scores = line[3:]
	easy = 0
	surprise = 0
	for val in scores:
		if val in vals:
			info = vals[val]
			if info[0] >= p:
				easy += 1
			elif info[1] >= p:
				surprise += 1
	if surprise > S:
		surprise = S
	print "Case #%d: %d" % (case_no, surprise + easy)
