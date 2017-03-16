t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
	num = int(raw_input())
	if num == 0:
		s='INSOMNIA'
		print "Case #{}: {}".format(i,s)
		continue 

	l10=[0,1,2,3,4,5,6,7,8,9]
	l10=set(l10)
	l=[]
	l=set(l)
	i1=1

	while True:		
		n = i1*num
		ns = str(n)
		l1=l.copy()
		for ch in ns:
			l.add(int(ch))

		if l10<=l:
			print "Case #{}: {}".format(i,n)
			break
		i1=i1+1