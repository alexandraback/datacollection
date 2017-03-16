from math import sqrt

def find_divisor(n):
	i=2
	while(i<=min(1000000,sqrt(n))):
		if(n%i==0):
			return i
		else:
			i=i+1
	return 0

def gen_nextbin(s,k):
	temp=int(s,2)
	temp=temp+1
	temp1=bin(temp)[2:]
	temp1=list(temp1)[::-1]
	n=len(temp1)
	while(n<k-2):
		temp1=temp1+['0']
		n=n+1
	temp1=temp1[::-1]
	return ''.join(temp1)

num_cases=50
cases=0
s='-1'
k=16
ans=[]

while(cases<num_cases):
	s=gen_nextbin(s,k)
	str1='1'+s+'1'
	tmp_ans=[]
	i=2
	while (i<11):
		int1=int(str1,i)
		t1=find_divisor(int1)
		if (t1==0):
			i=15
		else:
			tmp_ans=tmp_ans+[t1]
			i=i+1
	if(i==11):
		ans=ans+[[[str1]+tmp_ans]]
		cases=cases+1
		print cases

g=open('Csmall.txt','w')
g.write('Case #1: \n')
for i in range(0,num_cases):
	s=ans[i][0][0]+' '
	for j in range(1,9):
		s=s+str(ans[i][0][j])+' '
	s=s+str(ans[i][0][9])+'\n'
	g.write(s)

g.close()









