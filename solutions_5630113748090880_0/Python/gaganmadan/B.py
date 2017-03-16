f=open('B-small.in')
g=open('B-small.out','w')
from collections import Counter

def retstr(s):
	temp=Counter(s.split())
	temp2=''
	for x in temp:
		if(temp[x]%2==1):
			temp2=temp2+str(x)+' '
	a=temp2.split()
	b=[int(i) for i in a]
	b=sorted(b)
	c=[str(i) for i in b]
	temp3=' '.join(c)
	return temp3

t=int(f.readline())
for i in range(0,t):
	n=int(f.readline())
	temp=''
	for j in range(0,2*n-1):
		temp=temp+f.readline()
	g.write("Case #"+str(i+1)+": "+retstr(temp)+"\n")


f.close()
g.close()