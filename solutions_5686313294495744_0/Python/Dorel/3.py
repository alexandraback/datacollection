from itertools import permutations
from collections import defaultdict


T=int(raw_input())
for test in xrange(1,T+1) :
	N=int(raw_input())
	W=[]
	A=defaultdict(int)
	B=defaultdict(int)
	for w in xrange(N) :
		a,b = raw_input().strip().split()
		W.append((a,b))
		A[a]+=1
		B[b]+=1
	ans=0
	while len(W) :
		M,mx = [],2
		for a,b in W : mx=max(mx,A[a]+B[b])
		M=[ x for x in W if A[x[0]]+B[x[1]]==mx] 
		A1=set([x[0] for x in W if (A[x[0]]+B[x[1]]<mx)])
		B1=set([x[1] for x in W if (A[x[0]]+B[x[1]]<mx)])
		found=0
		for x in M :
			if (x[0] in A1 and x[1] in B1) :
				ans+=1
				W.remove(x)
				A[x[0]]-=1
				B[x[1]]-=1
				found=1	
				break
		if (found==0 and len(M)) : W.remove(M[0])
	print "Case #%d:"%test,ans 	
