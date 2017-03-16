t=int(raw_input())
for i1 in range(t) :
	n=int(raw_input())
	l=[[],[]]
	for i2 in range (n) :
		aux=raw_input()
		aux=aux.split()
		l[0].append(int(aux.pop(0)))
		l[1].append(int(aux.pop(0)))
	cond=True
	st=0
	naux=n
	resp=0
	while cond :
		cond=False
		cond2=True
		i2=0
		while i2 < n :
			if l[1][i2] <= st :
				if l[0][i2] == 10000 :
					st+=1
				else :
					st+=2
				l[1][i2]=10000
				l[0][i2]=10000
				cond=True
				cond2=False
				resp+=1
				break
			i2+=1
		i2=0
		m=-1
		im=-1
		while i2<n and cond2 :
			if l[0][i2]<=st :
				if l[1][i2]>m :
					m=l[1][i2]
					im=i2
			i2+=1
		if m>-1 :
			resp+=1
			cond=True
			l[0][im]=10000
			st+=1
	if n*2==st :
		print "Case #" + str(i1+1) + ": " + str(resp)
	else :
		print "Case #" + str(i1+1) + ": Too Bad"
