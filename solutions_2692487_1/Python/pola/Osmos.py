#!/usr/bin/env python2
import sys


cache = {}
def solve(A,N,p,m):

	res = 0
	if p == N:
		return res

	if ("%d-%d" % (A,p)) in cache:
		return cache["%d-%d" % (A,p)]

	if ( m[p] >= A ):
		# add mote
		res1 = 100000000000
		if(2*A-1) != A:
			res1 = solve(2*A-1,N,p,m)
		# remove mote
		res2 = solve(A,N,p+1,m)
		res =  1 + min (res1,res2)
	else:
		res = solve(A+m[p],N,p+1,m)

	cache["%d-%d" % (A,p)] = res
	return res

cases = int(sys.stdin.readline())

for case in range(cases):
	cache = {}
	line = [ int(x) for x in sys.stdin.readline()[:-1].split(" ") ]
	A = line[0]
	N = line[1]
	m = line = [ int(x) for x in sys.stdin.readline()[:-1].split(" ") ]
	m.sort()
	sol = solve(A,N,0,m)
	print "Case #%d: %d" % (case+1,sol)
		