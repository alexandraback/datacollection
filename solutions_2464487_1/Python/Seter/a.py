T=int(raw_input())
case=0
while T:
	T-=1
	case+=1
	r,t=raw_input().split()
	r=int(r)
	t=int(t)
	L=0
	R=int(1e18)
	while L+1!=R:
		x=(L+R)/2
		if (2*r+2*x+1)*(x+1)<=t:L=x
		else:R=x
	
	print "Case #"+str(case)+": "+str(R)
