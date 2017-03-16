f = open('B.out','w')
fin = open('B.in','r')
t=int(fin.readline().strip())
for i in range(t):
	count={}
	n=int(fin.readline().strip())
	for j in range(2*n-1):
		arr=map(lambda x: int(x) ,fin.readline().strip().split(' '))
		for item in arr:
			if item in count:
				count[item]=count[item]+1
			else:
				count[item]=1
	ans=[]
	for item in count:
		if count[item]%2==1:
			ans.append(item)
	ans.sort()
	result = "Case #"+str(i+1)+": "+' '.join(map(lambda x: str(x),ans))
	print result
	f.write(result+'\n')


fin.close()
f.close()
