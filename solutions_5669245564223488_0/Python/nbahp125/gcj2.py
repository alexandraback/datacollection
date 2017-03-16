# coding=utf-8
import sys,re,time,os,math,pdb

infile=open('a.in','r')
lines=infile.readlines()

def judge(str):
	a=set()
	a.add(str[0])
	for i in range(1,len(str)):
		if str[i]!=str[i-1]:
			if str[i] in a:
				return False
			else:
				a.add(str[i])
	return True
	
# count=0
# n=0
# cars=[]
# def f(num,str):
	# global count,cars
	# for i in range(0,n):
		# if i in num:
			# continue
		# else:
			# newstr=str+cars[i]
			# if judge(newstr):
				# newnum=[k for k in num]
				# newnum.append(i)
				# if len(newnum)==n:
					# count+=1
					# count=count%1000000007
				# else:
					# f(newnum,newstr)
count=1
def f(cars):
	global count
	#pdb.set_trace()
	zimu=[set() for k in cars]
	for i in range(0,len(cars)):
		for j in range(0,len(cars[i])):
			zimu[i].add(cars[i][j])
	for i in range(1,len(cars)):
		for j in range(0,i):
			if i==j:
				continue
			if len(zimu[i].intersection(zimu[j]))!=0:
				#pdb.set_trace()
				c=0
				newstr=''
				if judge(cars[i]+cars[j]):
					newstr=cars[i]+cars[j]
					c+=1
				if judge(cars[j]+cars[i]):
					newstr=cars[j]+cars[i]
					c+=2
				if c==2:
					return (j,i)
				if c==1:
					return (i,j)
				if c==0:
					return (-1,-1)
				
	return (-2,-2)
	
t=int(lines[0].strip())
outfile=open('res1.txt','w')
for i in range(1,t+1):
	n=int(lines[2*i-1].strip())
	cars=lines[2*i].split()
	count=1
	zimu=[set() for k in cars]
	for ti in range(0,len(cars)):
		for tj in range(0,len(cars[ti])):
			zimu[ti].add(cars[ti][tj])
	ttt={}
	for ti in range(len(cars)):
		if len(zimu[ti])==1:
			z=[k for k in zimu[ti]]
			z=z[0]
			if z not in ttt:
				ttt[z]=[]
			ttt[z].append(ti)
	cv=[]
	for z in ttt:
		sss=ttt[z]
		if len(sss)>1:
			for rrr in range(1,len(sss)+1):
				count*=rrr
			
			for rrr in range(1,len(sss)):
				cv.append(cars[sss[rrr]])
	for k in cv:
		cars.remove(k)
				
	for qi in range(0,n):
		if len(cars)==1:
			if judge(cars[0]):
				count*=1
			else:
				count=0
			break
		res=f(cars)
		if res==(-1,-1):
			count=0
			break
		elif res==(-2,-2):
			t=len(cars)
			for v in range(1,t+1):
				count*=v
			break
		else:
			t1=cars[res[0]]
			t2=cars[res[1]]
			cars.remove(t1)
			cars.remove(t2)
			cars.append(t1+t2)
		
	outfile.write('Case #'+str(i)+': '+str(count)+'\n')

	