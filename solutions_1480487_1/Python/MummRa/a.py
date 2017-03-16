
import sys, string, math, bisect
from itertools import permutations
rl = lambda: sys.stdin.readline().strip()

for cs in xrange(1,int(rl())+1):
	ns = map(int, rl().split())
	ns=ns[1:]
	n=len(ns)
	s=sum(ns)
	ans=""
	for xme in ns:
		besty=100
		theothers=ns[:]
		theothers.remove(xme)
		theothers.sort()
		zs=0
		for zcc,z in enumerate(theothers):
			zc=zcc+1
			zs+=z
			y=float(zs+s+-zc*xme)/((zc+1)*s)
			y=max(y,0)
			besty=min(y,besty)
#			print 'zzz',zc,z,zs,y,besty
		ans += " "+str(besty*100)
#		print
	print "Case #{0}:{1}".format(cs,ans)
	