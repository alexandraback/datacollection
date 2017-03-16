import fileinput
import math
stdin = fileinput.input()

def solveCase():
	C,D,V = map(int,stdin.next().split())
	ds = map(int,stdin.next().split())

	used = 0
	di = 0
	mex = 1
	while mex<=V:
		while di<D and 0<ds[di]<=mex<=V:
			mex += C*ds[di]
			di += 1
		if mex<=V:
			mex += C*mex
			used += 1
	return used

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())