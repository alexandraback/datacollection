#!/usr/bin/python3

import sys
import heapq

def docase():
	water0, h, w = (int(x) for x in sys.stdin.readline().split())
	cei = [[int(x) for x in sys.stdin.readline().split()] for i in range(h)]
	flo = [[int(x) for x in sys.stdin.readline().split()] for i in range(h)]
	accessible = [[max(0,water0-(cei[y][x]-50)) for x in range(w)] for y in range(h)]
	lastfast = [[max(0,water0-(flo[y][x]+20)) for x in range(w)] for y in range(h)]
	for y in range(h):
		for x in range(w):
			if cei[y][x] - flo[y][x] < 50:
				accessible[y][x] = 2000000
	#print(cei)
	#print(flo)
	#print(accessible)
	#print(lastfast)
	q = []
	reachtime = [[2000000]*w for y in range(h)]
	reachtime[0][0] = 0
	heapq.heappush(q, (0, 0, 0))
	def update(y, x, yfrom, xfrom, t1):
		if flo[yfrom][xfrom]+50 > cei[y][x]: return
		if flo[y][x]+50 > cei[yfrom][xfrom]: return
		if t1 < accessible[y][x]: t1 = accessible[y][x]
		t = t1
		if t1 > 0:
			t += 100 if t1>lastfast[yfrom][xfrom] else 10
		if t >= reachtime[y][x]: return
		reachtime[y][x] = t
		heapq.heappush(q, (t, y, x))
	while len(q):
		#print(q)
		t1, y, x = heapq.heappop(q)
		if y >= 1: update(y-1, x, y, x, t1)
		if y <= h-2: update(y+1, x, y, x, t1)
		if x >= 1: update(y, x-1, y, x, t1)
		if x <= w-2: update(y, x+1, y, x, t1)
	t = reachtime[h-1][w-1]
	return t/10.0

ncases = int(sys.stdin.readline())
case = 0
for case in range(ncases):
	sys.stdout.write("Case #%d: %0.1f\n" % (case+1, docase()))
