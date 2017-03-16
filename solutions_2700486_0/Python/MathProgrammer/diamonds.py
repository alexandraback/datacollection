from collections import*
from math import*

def REK(x,y,n,coords):
	if (x,y) in coords:
		return(1)
	if n==0:
		return(0)
	i=0
	ymax0=-1
	for coor in coords:
		if coor[0]==0:
			ymax0=max([ymax0,coor[1]])
	
	if ymax0==-1:
		coords.add((0,0))
		return(REK(x,y,n-1,coords))
	
	plus=0
	minus=0
	p=0
	m=0
	curry=ymax0+2
	currx=0
	sum=0
	if (currx+1,curry-1) not in coords:
		cy=curry
		cx=0
		while (cx+1,cy-1) not in coords and cy-1>=0:
			cx+=1
			cy-=1
		coords.add((cx,cy))
		p=REK(x,y,n-1,coords)
		coords.remove((cx,cy))
		plus=1
	
	if (currx-1,curry-1) not in coords:
		cy=curry
		cx=0
		while (cx-1,cy-1) not in coords and cy-1>=0:
			cx-=1
			cy-=1
		coords.add((cx,cy))
		m=REK(x,y,n-1,coords)
		coords.remove((cx,cy))
		minus=1
	
	if plus:
		if minus:
			return(p/2+m/2)
		else:
			return(p)
	if minus:
		return(m)
	
	coords.add((0,curry))
	pro=REK(x,y,n-1,coords)
	coords.remove((0,curry))
	return(pro)
	

data=[]
f=open("B-small-attempt0.in.txt","r")
T=int(f.readline())
for i in range(T):
	data.append([int(j) for j in f.readline().split()])
f.close()

cases=[]
for d in data:
	(X,Y)=tuple(d[1:])
	N=d[0]
	if (sqrt(8*N+1)-1)//2-1<Y:
		cases.append(0)
	else:
		cases.append(REK(X,Y,N,set()))

fut=open("ANS.txt","w+")
for i in range(T):
	fut.write("Case #{}: {}\n".format(i+1,cases[i]))
fut.close()
