import math

inf = open('in','r')
T = int(inf.readline())

for c in xrange(T):
	l = inf.readline().split()
	r, t = int(l[0]), int(l[1])
	b = 2.0*r - 1.0
	x = int(0.25*(math.sqrt(b*b + 8.0 * t)-b))
	while x*(2*(x+r)-1) < t: x+=1
	while x*(2*(x+r)-1) > t: x-=1
	print 'Case #' + str(c+1) + ': ' + str(x)
	
