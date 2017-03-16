#!/usr/bin/python
# Google code 2013
inf = open('input.txt')
outf = open('output.txt','w')
t = inf.readlines()
n = int(t[0].rstrip())

i=0
while i<n:
	e=t[i+1].rstrip().split(' ')
	r=int(e[0])
	T=int(e[1])
	i=i+1
	c=0
	while ((r+1)**2-r**2)<=T:
		T=(T+(r**2)-((r+1)**2))
		r=r+2
		c=c+1
	outf.write("Case #"+str(i)+": "+str(c)+'\n')
