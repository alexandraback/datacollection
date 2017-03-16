#!/usr/bin/env python2
import sys

def solve(A,N,p,m):

	res = 0
	if p == N:
		return res

	if ( m[p] >= A ):
		# add mote
		res1 = 100000
		if(2*A-1) != A:
			res1 = solve(2*A-1,N,p,m)
		# remove mote
		res2 = solve(A,N,p+1,m)
		res =  1 + min (res1,res2)
	else:
		res = solve(A+m[p],N,p+1,m)
	return res

cases = int(sys.stdin.readline())

for case in range(cases):
	stack = []
	line = [ int(x) for x in sys.stdin.readline()[:-1].split(" ") ]
	A = line[0]
	N = line[1]
	m = line = [ int(x) for x in sys.stdin.readline()[:-1].split(" ") ]
	m.sort()
	sol = solve(A,N,0,m)
	print "Case #%d: %d" % (case+1,sol)
		