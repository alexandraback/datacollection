t=int(input())

for i in xrange(1,t+1) :
	d=int(input())
	cakes=map(int,raw_input().split())
	maxx=max(cakes)
	ans=maxx
	for j in xrange(maxx-1,0,-1) :
		special=0
		for cake in cakes :
			if j<cake :
				special+=(cake/j)
				if not cake%j :
					special-=1
		if j+special<ans :
			ans=j+special
		
	print "Case #%d: %d"%(i,ans)
