#!/usr/bin/python3

import sys
import operator

sys.stdin.readline()

case = 0
for line in sys.stdin:
	case += 1
	d = {}
	k = 0
	ava = 0
	for i in line.split()[1:]:
		d[k] = int(i)
		ava += d[k]
		k += 1
	ssum = ava
	d = sorted(d.items(), key=operator.itemgetter(1))
	level = d[0][1]
	for i in range(len(d)-1):
		need = (d[i+1][1]-d[i][1])*(i+1)
		if ava >= need:
			level = d[i+1][1]
			ava -= need
		else:
			level += (ava*1.0)/(i+1)
			ava = 0
			break
	if ava > 0:
		level += (ava*1.0)/len(d)
	out = [0.0]*len(d)
	for i in range(len(d)):
		t = (level - d[i][1])
		if t < 0: t = 0
		out[d[i][0]] = 100.0*t/ssum
	sys.stdout.write("Case #"+str(case)+":")
	for n in out:
		sys.stdout.write(" %.8f"%n,)
	sys.stdout.write("\n")
