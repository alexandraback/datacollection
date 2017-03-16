#!/usr/bin/python

# C. wall 

import sys
import math

wall = [0] * 801
base = 400
d = []
n = []
w = []
e = []
s = []
dd = []
dp = []
ds = []

f = sys.stdin
T = int(f.readline())

for case in range(1, T+1) :
	wall = [0] * 801
	d = []
	n = []
	w = []
	e = []
	s = []
	dd = []
	dp = []
	ds = []

	N = int(f.readline())
	for j in range(N):
		line = [int(i) for i in f.readline().split()]
		d.append(line[0])
		n.append(line[1])
		w.append(line[2] * 2 + base)
		e.append(line[3] * 2 + base + 1)
		s.append(line[4])
		dd.append(line[5])
		dp.append(line[6] * 2)
		ds.append(line[7])
	
	ret = 0

	currentDay = 0
	while max(n) > 0 and currentDay <= 676060:
		interval = []
		for i in range(N):
			if d[i] != currentDay: continue
			if n[i] <= 0: continue

			broken = False
			for l in range(w[i], e[i]):
				if wall[l] < s[i]:
					broken = True
					break
			if broken:
				ret += 1
				interval.append(w[i])
				interval.append(e[i])
				interval.append(s[i])

			n[i] -= 1
			if n[i] <= 0:
				d[i] = 987654321
			else:
				d[i] += dd[i]
			w[i] += dp[i]
			e[i] += dp[i]
			s[i] += ds[i]
			
		for i in range(0, len(interval), 3):
			for j in range(interval[i], interval[i+1]):
				wall[j] = max(wall[j], interval[i+2])
		
		currentDay = min(d)

	print "Case #%d: %d" % (case, ret)
