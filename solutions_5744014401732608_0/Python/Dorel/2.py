from __future__ import print_function	
T=int(raw_input())
for test in xrange(1,T+1):
	N,M=[int(x) for x in raw_input().split()]
	E=(N*(N-1))/2
	found=0
	for s in xrange(2**E) :
		t=s
		p=[0 for x in xrange(N)]
		p[0]=1	
		for b in xrange(1,N) :
			for a in xrange(b) :
				if t&1 : 
					p[b]+=p[a] 
				t/=2
				
		if p[N-1]==M : 
			print("Case #%d: POSSIBLE"%test)
			t=s
			e=[[0 for x in xrange(N)] for y in xrange(N)]
			for b in xrange(1,N) :
				for a in xrange(b) :
					if t&1 : e[a][b]=1
					t/=2
			for b in xrange(N-1) :
				for a in xrange(N) : print(e[b][a],sep='',end='')
				print()	
			print('0'*N)
			found=1
			break
		if found==1 : break
		
	if found==0 : 	 
			print("Case #%d: IMPOSSIBLE"%test)
