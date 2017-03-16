from itertools import permutations


T=input()

for test in xrange(1,T+1) :
	N=input()
	f=[ int(x)-1 for x in raw_input().split() ]
	for mx in xrange(N,1,-1) :
		check=0
		for p in permutations(range(N), mx) :
			if (f[p[mx-1]]==p[0]) :
				found=0
				for ix in xrange(mx-1) : 
					if (not f[p[ix]] in (p[(ix+1)%mx], p[ix-1])) :
						found=1
						break				
				if (found==0) :
					check=1
					break
		if (check==1) : 
			print "Case #%d: %d"%(test,mx) 
			break	


