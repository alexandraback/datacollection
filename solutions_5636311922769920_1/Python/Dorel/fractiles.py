from __future__ import print_function

f=open("input")
T=int(f.readline().strip())

for test in xrange(1,T+1):
	K, C, S = [ int(x) for x in f.readline().strip().split()]
	if (K==S) :
		print("Case #%d: "%test, end='')
		for i in xrange(1,K+1) : print("%d "%i, end='')
		print()
	elif (C==1 or S*C<K) :
		print("Case #%d: IMPOSSIBLE"%test)
	else :
		print("Case #%d: "%test, end='')
		residues = range(K)
		for i in xrange(0,K,C) :
			print("%d "%(1+sum([ x*(K**(x%C)) for x in residues[i:i+C]])),end='')
		print()
		

