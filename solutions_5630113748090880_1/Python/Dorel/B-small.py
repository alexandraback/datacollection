T=input()

for test in xrange(1,T+1) :
	N=input()
	v=[]
	for x in xrange(2*N-1) :
		v.append([ int(x) for x in raw_input().split()])
	solution=[]
	while (N>1) :
		first_col=[y[0] for y in v]
		smallest= min(first_col)
		if (first_col.count(smallest)==2) :
			x,y = [ z for z in v if (z[0]==smallest)]
			tmp=x+y
			for a in first_col :
				tmp.remove(a)
			solution.append(tmp[0])
			v.remove(x)
			v.remove(y)
			for ix in xrange(len(v)) :
				v[ix]=v[ix][1:]
			N=N-1
			if (N==1) : solution.append(v[0][0])
		else : # first column missing
			first_row = [ z for z in v if (z[0]==smallest)][0]
			for a in first_row[1:] :
				first_col.remove(a)
			solution += sorted(first_col)
			break
			
	print "Case #%d:"%test,
	for x in solution : print x,
	print	


