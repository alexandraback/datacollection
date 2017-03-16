#!/usr/bin/env python
filein=open('input_l','r')
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
all=[]
for i in range(1,10000000+1):
		if True==check_palin(i) and True==check_palin(i**2):
			all.append(i**2)


t=int(t)
for i in range(1,t+1):
	temp=filein.readline()
	#temp=raw_input()
	temp=temp.split(' ')
	a=int(temp[0])
	b=int(temp[1])
	#####input ends
	number=0
	for num in all:
		if num>=a and num <=b:
			number+=1
	#print "Case #"+str(i)+": "+str(number)+"\n"
	fileout.write("Case #"+str(i)+": "+str(number)+"\n")
filein.close()
fileout.close()
	
