n=[]
f = open('A.out','w')
fin = open('A.in','r')
t=int(fin.readline().strip())
for i in range(t):
	n.append(list(fin.readline().strip()))
fin.close()
for j in range(t):
	ans=[n[j][0]]
	for k in range(1,len(n[j])):
		if(n[j][k]>=ans[0]):
			ans.insert(0,n[j][k])
		else:
			ans.append(n[j][k])

	result = "Case #"+str(j+1)+": "+''.join(ans)
	print result
	f.write(result+'\n')
f.close()