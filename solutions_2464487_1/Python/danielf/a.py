from math import sqrt

def find(r,t):
	L = int((-(2*r-1) + sqrt( (2*r-1)**2 + 8*t))/4)
	L -= 10
	while L*(2*L-1) + 2*r*L <= t:
		L += 1
	return L - 1

T = int(raw_input())
for s in xrange(T):
	r,t = [int(x) for x in raw_input().split(' ')]
	L = find(r,t)
	print "Case #%d: %d" % (s+1, L)
