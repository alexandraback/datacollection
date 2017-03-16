def gao(now,r,t):
	l=r+now*2-2
	sum=(l+r)*now+now
	if sum>t:
		return False
	else:
		return True
if __name__ == '__main__':
	T=input()
	g=1
	for i in xrange(T):
		r,t=map(int,raw_input().split())
		le=1
		ri=10000000000000
		while le<ri:
			mid=(le+ri+1)/2
			if gao(mid,r,t):
				le=mid
			else:
				ri=mid-1;
		print "Case #%d: %d"%(g,le)
		g+=1
