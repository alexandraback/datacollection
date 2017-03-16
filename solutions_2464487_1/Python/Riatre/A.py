import os,sys

def sumit(first,n):
	return (first+first+(n-1)*4)*n/2

def solve(r,t):
	left = 0
	right = 2*int(1e18)
	while left < right:
		mid = (left+right)//2
		if sumit(2*r+1,mid) <= t: left = mid+1
		else: right = mid

	return left-1

T = input()

for TK in xrange(1,T+1):
	r,t = map(int,raw_input().split())
	print 'Case #%d: %s' % (TK,str(solve(r,t)))
