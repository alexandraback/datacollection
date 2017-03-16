f=open("A-small-attempt0.in","r")
g=open("A-small-attempt0.out","w")

def isVovel(r):
	return r== 'a' or r == 'e' or r=='i' or r=='o' or r=='u'
T=int(f.readline()) 
for t in xrange(1,T+1):
	g.write("Case #"+str(t)+": ")
	[L,ntemp]=f.readline().split()
	n=int(ntemp);
	value=[]
	summ=[]
	x=0
	for r in L:
		if isVovel(r) :
			value.append(0)
		else:
			value.append(1)
			x+=1
		summ.append(x)
	ans=0
	dp=[0 for a in xrange(len(value))]
	for i in xrange(len(value)):
		if i>n-1:
			if isVovel(L[i]):
				dp[i]=dp[i-1]
			else:
				if summ[i]-summ[i-n]==n:
					dp[i]=i-n+2
				else:
					dp[i]=dp[i-1]

		if i==n-1 and summ[i]==n:
			dp[i]=1
		print i,L[i],dp[i]
		ans+=dp[i]
	g.write(str(ans)+"\n")

f.close
g.close