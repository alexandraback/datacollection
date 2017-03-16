from random import shuffle

for T in range(input()):
	R=[]
	c=0
	for N in range(input()):
		R.append(raw_input().split())

	for j in range(300):
		r=0
		shuffle(R)
		L=map(list,zip(*R))

		i=0
		while i<len(L[0]):
			if L[0].count(L[0][i]) > 1:
				if L[1].count(L[1][i]) > 1:
					r+=1
					L[0].pop(i)
					L[1].pop(i)
					i-=1
			i+=1
		c = max(c,r)
	print "Case #%d: %d" % (T+1,c)
	
