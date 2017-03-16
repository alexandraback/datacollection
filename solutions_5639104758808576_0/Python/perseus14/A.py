T=input()
for t in xrange(1,T+1):
	n,s=raw_input().split()
	n=int(n)
	print "Case #%d:"%t,
	sum1=0
	count=0
	l=len(s)
	for x in s:
		sum1+=int(x)
	ans=0
	x=0
	while(x<l):
		if(count>=x):
			count+=int(s[x])
			x+=1
		else:
			ans+=x-count
			count+=x-count
	print ans
