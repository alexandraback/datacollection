
import sys, string, math, bisect
rl = lambda: sys.stdin.readline().strip()

for cs in xrange(1,int(rl())+1):
	x,y = [int(z) for z in rl().split()]
	#print x,y
#	print "Case #{0}: {1}".format(cs,num_subs)
	path=""
	incx="WE" if x>=0 else "EW"
	incy="SN" if y>=0 else "NS"

	for i in xrange(abs(x)):
		path += incx
	for i in xrange(abs(y)):
		path += incy

	print "Case #{0}: {1}".format(cs, path)






