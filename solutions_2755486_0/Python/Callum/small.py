def successfulattacks(tribes):
	successful=0
	attacks=[]
	for i in tribes:
		for q in range(i[1]):
			temp=[]
			temp.append(i[2])
			temp.append(i[3])
			temp.append(i[4])
			temp.append(i[0])
			attacks.append(temp)
			i[0]+=i[5]
			i[2]+=i[6]
			i[3]+=i[6]
			i[4]+=i[7]
	attacks=sorted(attacks,key=lambda a: a[3])
	fareast=min(attacks,key=lambda a: a[0])[0]
	farwest=max(attacks,key=lambda a: a[1])[1]
	maxDay=max(attacks,key=lambda a: a[3])[3]
	offset=0-fareast
	for i in attacks:
		i[0]+=offset
		i[1]+=offset
	wallHeight=[0]*400
	for i in range(maxDay+1):
		todayAttacks=[a for a in attacks if a[3]==i]
		for a in todayAttacks:
			if min(wallHeight[a[0]:a[1]])<a[2]:
				successful+=1
		for a in todayAttacks:
			for q in range(a[0],a[1]):
				wallHeight[q]=max(a[2],wallHeight[q])
	return successful
lines=[i.replace('\n','') for i in open('C-small-attempt1.in','r').readlines()[1:]]
out=open('output.txt','w')
curCase=1
i=0
while i<len(lines):
	ntribes=int(lines[i])
	tribes=[]
	for q in range(ntribes):
		tribes.append([int(j) for j in lines[i+q+1].split()])
	out.write(('Case #{0}: '+str(successfulattacks(tribes))+'\n').format(curCase))
	i+=ntribes+1
	curCase+=1