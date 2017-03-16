N=input()
for n in range(N):
	S=[int(t) for t in raw_input().split()]
	[M,s,p]=S[:3]
	T=S[3:]
	Tx=[[t,t//3,t%3] for t in T]
	for t in Tx:
		if t[2]==1 or t[2]==2: t[1]=t[1]+1
	#print s,p,Tx
	Ty=[t for t in Tx if t[1]<p]
	Ts=[t for t in Ty if t[1]+1>=p and t[2]!=1 and (t[2]==2 or (t[0]//3>0))]
	#print Ty
	#print Ts
	print "Case #%d: %d" % (n+1,M-len(Ty)+len(Ts)-max(len(Ts)-s,0))
