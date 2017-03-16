import numpy as np
for i in xrange(1,input()+1):
	N=input()
	z=np.array(N**2*2-N)
	SS=[]
	for j in xrange(N*2-1):
		S=map(int,raw_input().split())
		SS.extend(S)
	f=[]
	for j in SS:
		if SS.count(j)%2!=0:
			if j not in f:
				f.append(j)
	f.sort()
	print "Case #{}:".format(i),
	for j in f:
		print j,
	print