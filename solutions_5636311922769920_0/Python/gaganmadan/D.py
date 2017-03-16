from math import ceil,pow

def out(K,C):
	ans=[]
	i=0;
	temp=0
	while(i<ceil(float(K)/float(C))-1):
		j=1
		temp=0
		while(j<=C):
			temp=temp+(i*C+(j-1))*int(pow(K,C-j))
			j=j+1
		ans=ans+[temp+1]
		i=i+1
	temp=i*C
	j=1
	s=0
	while(temp<K):
		s=s+(temp)*int(pow(K,C-j))
		j=j+1
		temp=temp+1
	ans=ans+[s+1]
	return ans

f=open('D-small.in')
g=open('Dsmall.txt','w')

n=f.readline()
run=1
for line in f:
	a=line.split()
	K=int(a[0])
	C=int(a[1])
	S=int(a[2])
	if(S<ceil(float(K)/float(C))):
		g.write('Case #'+str(run)+': '+'IMPOSSIBLE'+'\n')
	else:
		temp=out(K,C)
		temp_arr=[str(x) for x in temp]
		str1=' '.join(temp_arr)
		g.write('Case #'+str(run)+': '+str1+'\n')
	run=run+1

f.close()
g.close()

