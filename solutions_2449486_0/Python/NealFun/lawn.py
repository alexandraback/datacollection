#!/usr/bin/env python
filein=open('input_s','r')
fileout=open('result','w')
t=filein.readline()
t=int(t)
for i in range(1,t+1):
	temp=filein.readline()
	temp=temp.split(' ')
	n=int(temp[0])
	m=int(temp[1])
	lawn=[]
	for j in range(0,n):
		temp=filein.readline()
		row=[]
		temp=temp.split(' ')
		for k in range(0,m):
			row.append(int(temp[k]))
		lawn.append(row)
	#####input ends
	cutrow=[0 for x in range(n)]
	maxrow=0
	for j in range(0,n):
		maxrow=0
		for k in range(0,m):
			if lawn[j][k]>maxrow:
				maxrow=lawn[j][k]
		cutrow[j]=100-maxrow
	#####end of getting the cut of each row
	cutcol=False
	cutposs=True
	for j in range(0,m):
		cutcol=False
		for k in range(0,n):
			if lawn[k][j]!=100-cutrow[k]:
				cutcol=True
		if cutcol==True:
			for k in range(0,n):
				if lawn[k][j]!=lawn[0][j]:
					cutposs=False
					break

	if cutposs==False:
		fileout.write("Case #"+str(i)+": "+"NO\n")
	else:
		fileout.write("Case #"+str(i)+": "+"YES\n")

