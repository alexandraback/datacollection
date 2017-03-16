#!/usr/bin/env python
filein=open('input_s','r')
fileout=open('result','w')
t=filein.readline()
from math import sqrt
def check_palin(a):
	b=str(a)
	length=len(b)
	for i in range(0,length):
		if i>length-i-1:
			break
		if b[i]!=b[length-i-1]:
			return False
	return True
#t=raw_input()
t=int(t)
for i in range(1,t+1):
	temp=filein.readline()
	#temp=raw_input()
	temp=temp.split(' ')
	a=int(temp[0])
	b=int(temp[1])
	#####input ends
	number=0
	for j in range(int(sqrt(a)),int(sqrt(b))+1):
		if j**2<a or j**2>b:
			continue
		if True==check_palin(j) and True==check_palin(j**2):
			number+=1
	
	#print "Case #"+str(i)+": "+str(number)+"\n"
	fileout.write("Case #"+str(i)+": "+str(number)+"\n")
filein.close()
fileout.close()
	
