data=open("B-small-attempt0 (1).in","r")
s1=data.read()
s1=s1.split("\n")
cou=0
t=int(s1[cou])
cou+=1#int(input())#int(s1[0])
for i in range(1,t+1):
	n=int(s1[cou])#int(input())
	cou+=1
	l=[]
	l1=[0 for j in range(2500)]
	for j in range(2*n-1):
		s=s1[cou]
		cou+=1
		l.append(list(map(int,s.split())))
	for j in range(2*n-1):
		for k in range(n):
			l1[l[j][k]-1]+=1
	l=[]
	s="Case #{0}:".format(i)
	for j in range(len(l1)):
		if(l1[j]%2!=0):
			s=s+" "+str(j+1)
	print(s)
