import sys

def my_binary(r, t, low, high):
	mid = low + (high-low)/2
	tcheck = (2*r-1)*mid + 2*mid**2
	if (high <= low or low == mid):
		return low
	if (tcheck == t):
		return mid
	elif tcheck < t:
		return my_binary(r,t, mid, high)
	else:
		return my_binary(r,t, low, mid)

def solve():
	(r, t) = tuple(map(int, sys.stdin.readline().split()))
	return my_binary(r,t,0,t)
t = int(sys.stdin.readline())
for i in xrange(1,t+1):
	print "Case #%i: %i" % (i, solve())

