ncases = int(raw_input())
for c in range(0,ncases):
	N,M =  [int(x) for x in raw_input().split()]
	boxes = []
	toys = []
	tmpBoxes = [int (x) for x in raw_input().split()]
	tmpToys = [int (x) for x in raw_input().split()]
	nboxedToys = 0
	i = N-1
	j = M-1
	while (i>=0 and j>=0):
		btype = tmpBoxes[2*i+1]
		ttype = tmpToys[2*j+1]
		boxed = 0
		if btype == ttype:
			boxed = min(tmpBoxes[2*i], tmpToys[2*j])
			nboxedToys += boxed
			tmpBoxes[2*i]-=boxed
			tmpToys[2*j]-=boxed
		#print btype, ttype, i ,j,tmpBoxes[2*i], tmpToys[2*j], boxed
		maxThrowBox = 0
		maxThrowToy = 0
		k = i-1
		while(k>=0):
			if (tmpBoxes[2*k+1]==tmpToys[2*j+1]):
				maxThrowBox = min (tmpBoxes[2*k],tmpToys[2*j])
				break
			k  = k-1
		k = j-1
		while(k>=0):
			if (tmpBoxes[2*i+1]==tmpToys[2*k+1]):
				maxThrowToy = min (tmpBoxes[2*i],tmpToys[2*k])
				break
			k  = k-1
		if (maxThrowBox  >= maxThrowToy):
			i  = i-1
		else:
			j = j-1
		

	print "Case #{0}: {1}".format(c+1, nboxedToys)