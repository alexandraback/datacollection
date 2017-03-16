T=int(raw_input())
for repeat in xrange(T):
	N=int(raw_input())
	level_1=[]
	level_2=[]
	for i in xrange(N):
		line=raw_input().split()
		level_1.append(int(line[0]))
		level_2.append(int(line[1]))
	stars=0
	count=0
	main=True
	while stars<2*N and main==True:
		main=False
		flag=True
		while flag==True:
			flag=False
			for i in xrange(N):
				if level_2[i]>=0 and level_2[i]<=stars:
					stars+=2
					count+=1
					level_2[i]=-1
					level_1[i]=-1
					flag=True
					main=True
		level_id,level_max=-1,-1
		for i in xrange(N):
			if level_1[i]>=0 and level_1[i]<=stars:
				if level_2[i]==-1:
					stars+=1
					count+=1
					level_1[i]=level_2[i]
					level_2[i]=-1
					main=True
					level_id,level_max=-1,-1
					break
				elif level_2[i]>level_max: level_id,level_max=i,level_2[i]
		if level_id!=-1:
			stars+=1
			count+=1
			level_1[level_id]=level_2[level_id]
			level_2[level_id]=-1
			main=True
	print "Case #%d:"%(repeat+1),
	if stars==2*N: print count
	else: print "Too Bad"
