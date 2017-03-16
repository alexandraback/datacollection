from itertools import combinations
T = input()
for t in xrange(1,T+1):
	L = map(int,raw_input().split())
	c=L[0]
	d=L[1]
	v=L[2]
	den=[int(i) for i in raw_input().split()]
	has=[0]*(v+1)
	has[0]=1
	for i in den:
		has[i]=1
	all_poss=[]
	for x in range(1,len(den)+1):
		for subset in combinations(den,x):
			all_poss+=[sum(subset)]
	for i in all_poss:
		if(i<=v):
			has[i]=1
	ans=0
	for i in xrange(0,v+1):
		if(has[i]==0):
			ans+=1
			den+=[i]
			has[i]=1
			for x in range(1,len(den)+1):
				for subset in combinations(den,x):
					all_poss+=[sum(subset)]
			for i in all_poss:
				if(i<=v):
					has[i]=1
	print "Case #%d:"%t,
	print ans
