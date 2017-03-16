f=open('out.out', 'w')
t=input()
for tc in range(1,t+1):
	smax,P=raw_input().split()
	smax=int(smax)
	A=[int(i) for i in P]
	S=[None]*(smax+1)
	S[0]=A[0]
	for i in range(1,smax+1):
		S[i]=S[i-1]+A[i]
	cur,ppl=S[0],0
	while cur+ppl<(smax+1):
		# print cur, ppl
		if cur+ppl==S[cur+ppl]+ppl:
			ppl+=1
		else:
			cur=S[cur+ppl]
	f.write("Case #"+str(tc)+": "+str(ppl)+"\n")
	# print "Case #%i: %i" % (tc, ppl)