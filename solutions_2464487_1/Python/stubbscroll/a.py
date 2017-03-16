import sys
lines=sys.stdin.readlines()
T=int(lines[0])
for z in xrange(T):
	no=z+1
	p=lines[no].split(" ");
	r=int(p[0])
	t=int(p[1])
	lo=0
	hi=10000000000
	while lo<hi:
		mid=(lo+hi)/2
		use=2*r*(mid+1)
		use+=(mid+1)*(2*mid+1)
		if use<=t:
			lo=mid+1
		else:
			hi=mid
	print "Case #%d: %d"%(no,lo)
