import string

f=open(r'B_smallinput.in', 'r')
N=f.readline()
N=N.rsplit( )[0]
N=int(N)
for i in range(1, N+1) :
	n=f.readline()
	n=n.rsplit( )[0]
	n=int(n)
	r=0
	R=0
	a = []
	b = []
	round = [] 
	count = 0
	for j in xrange(0,n):
		line=f.readline()
		line=line.rstrip("\n\r ")
		line=line.split(' ')
		a.append(int(line.pop(0)))
		b.append(int(line.pop(0)))
	# print a
	# print b
	for j in xrange(0,n):
		round.append(0)
	while(R!=n) :
		flag = 0
		for j in xrange(0, n):
			if(b[j] <= r and round[j]!=2):
				count+=1
				if(round[j]==0):
					r+=2
				if(round[j]==1):
					r+=1
				round[j] = 2
				flag = 1
				R+=1
				break
		if (flag == 0):
			fb = 0
			for j in xrange(0, n):
				if(a[j] <= r and round[j]==0):
					if (b[j] > fb):
						fj = j
						fb = b[j]
			if(fb!=0):
				round[fj] = 1
				r+=1
				count+=1
				flag = 2
		if(flag == 0):
			break
	if(R<n):
		print 'Case #{0}: {1}'.format(i, "Too Bad")
	else:
		print 'Case #{0}: {1}'.format(i, count)
		
	#for j in xrange(0,count):
	#	if (l[j] == 3*p-4 or l[j] == 3*p-3) and p-2>0 :
	#		surprises+=1
	#	if l[j] >= 3*p-2:
	#		ans+=1

	# if s <= surprises:
	#	ans+=s
	#else:
	#	ans+=surprises
	
	#print 'Case #{0}: {1}'.format(i, ans)
