def find_n(n):
	temp=False
	i=1
	j=1
	a='0987654321'
	b=set(list(a))
	set1=([])
	while(not(temp)):
		j=n*i
		set1=set(list(str(j))).union(set1)
		if(set1.intersection(b)==b):
			temp=True
		else:
			i=i+1
	return i*n





f=open('A-large.in')
g=open('Alarge.txt','w')
n=int(f.readline())
i=1
for line in f:
	line.replace('\n','')
	temp=int(line)
	if (temp!=0):
		g.write('Case #'+str(i)+': '+str(find_n(temp))+'\n')
	else:
		g.write('Case #'+str(i)+': '+'INSOMNIA'+'\n')
	i=i+1

	


f.close()
g.close()





