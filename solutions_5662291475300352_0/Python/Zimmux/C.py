import fileinput
stdin = fileinput.input()

import math

def det(p,q):
	return p[0]*q[1]-p[1]*q[0]

def intersections(l1,l2):
	dy1,y1 = l1
	dy2,y2 = l2
	# y1+x*dy1=y2+x*dy2
	# (y1-y2)/(dy2-dy1)=x
	num = y1-y2
	den = dy2-dy1
	if den != 0:
		x = num/den
		yield (x,y1+x*dy1)

def solveCase():
	n = map(int,stdin.next().split())[0]
	dhm = [ tuple(map(int,stdin.next().split())) for i in range(n) ]
	ds,hs,ms = zip(*dhm)
	tot = sum(hs)
	lines = [
		( 360./(m+i) # dy
		, d-360*t # y
		)
		for d,h,m in dhm
		for i in xrange(h)
		for t in xrange(tot)
	]
	lines = sorted(lines)
	if tot==0:
		return 0
	if tot==1:
		return 0
	if tot==2:
		slow,fast = lines[1],lines[2]
		for (x,y) in intersections(slow,fast):
			if 0<=y<=360:
				return 1
		return 0
	if tot>2:
		return 0

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())