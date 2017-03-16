import math

def maxprint(r, t):
	f = lambda x: 2*x*x + (2*r-1)*x - t
	fp = lambda x: 4*x + 2*r - 1
	xn = math.sqrt(t)
	fx = f(xn)
	#print xn, fx
	while abs(fx) > 0.000001:
		xn = xn - fx/fp(xn)
		fx = f(xn)
		#print xn, fx
	xn = int(xn)
	for x in range(xn+1, max(xn-2,0), -1):
		fx = f(x)
		#print x, fx
		if fx<=0:
			return x

k = int(raw_input())
for i in range(0, k):
	r, t = [int(x) for x in raw_input().split()]
	result = maxprint(r, t)
	print 'Case #%s: %s' % (i+1, result)