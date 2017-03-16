#!/usr/bin/python

import sys

def r():
        for line in sys.stdin:
                for tok in line.strip().split():
                        yield tok
inp = r()

t = int(inp.next())
for case in range(t):
	n = int(inp.next())
	points = []
	for i in range(n):
		points.append(int(inp.next()))
	total = sum(points)
	mystr = "Case #" + str(case+1) + ":"
	for i in range(n):
		resto = sum(points[0:i]) + sum(points[i+1:])
		x = total + resto - (n-1)*points[i]
		need = x/n
		if(need < 0): need = 0.0
		mystr = mystr + " " + str(100*need/float(total))
	print mystr
