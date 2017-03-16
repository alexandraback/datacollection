#!/usr/bin/python3

import sys

# Ignore the number of cases
sys.stdin.readline()

casenum = 0
for line in sys.stdin:
	casenum += 1

	data = line.strip().split(' ')
	contestants = int(data[0])
	points = data[1:]

	total = 0
	for p in points:
		total += int(p)

	res = {}
	neg = 0
	nneg = 0
	for c in range(0, contestants):
		m = 100 * (2 * (total/contestants) - int(points[c])) / total
		if m<0:
			nneg += 1
			neg += m
		res[c] = m

	restxt = ""
	for c in range(0, contestants):
		if res[c]<0: res[c] = 0
		else: res[c] += neg/(contestants-nneg)
		restxt += " %0.6f" % res[c]

	print("Case #%d:%s" % (casenum, restxt))
