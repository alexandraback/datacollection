def check(n,r,t):
	res=2*(n*r+n*(n-1))+n
	
	if res>t:
		return False
	else:
		return True
if __name__ == '__main__':
	T=input()
	ys=1
	for i in xrange(T):
		r,t=map(int,raw_input().split())
		left=0
		right=t/(2*r+1)
		while left<right:
			mid=(left+right+1)/2
			if check(mid,r,t):
				left=mid
			else:
				right=mid-1;
		print "Case #%d: %d"%(ys,left)
		ys+=1
