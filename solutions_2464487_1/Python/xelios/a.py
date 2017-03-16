import sys
import math

def calcpaint(r,cnt):
	return (2*r+cnt*2-1) * cnt

def search(mn, mx, r, t):
	while mn<mx:

		mid = (mx+mn)/2
		calc = calcpaint(r, mid)
		if t <= calc:
			mx = mid
		else:
			mn = mid+1

	if calcpaint(r,mx)<=t and calcpaint(r, mx+1)>t: return mx
	else: return mx-1

def solve():
	r,t = map(int, sys.stdin.readline().strip().split())
	return search(0, sys.maxint*10000, r, t)

T = int(raw_input())
for x in xrange(T):
	print "Case #" + str(x+1) + ": " + str(solve())