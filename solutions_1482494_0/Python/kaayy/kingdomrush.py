#!/usr/bin/env python

import sys

def solvecase(N,levels):
	heap=[(-1*stars,levels[i][stars-1],-1*levels[i][1],i) for stars in range(1,3) for i in range(0,N)]
	heap=sorted(heap)
	#print(heap)
	status=[0 for i in range(0,N)]
	finished=False
	currentstars=0;
	times=0
	while not finished:
		finished=True
		toremove=None
		for elem in heap:
			(stars,required,required2,level)=elem
			if required<=currentstars and (-1*stars)>status[level]:
				if stars==-2:
					if status[level]==1:
						currentstars+=1
					elif status[level]==0:
						currentstars+=2
					status[level]=2
				else: #stars=-1
					currentstars+=1
					status[level]=1
				finished=False
				times+=1
				toremove=elem
				#print(stars,required,level,currentstars)
				break
		if not finished:
			heap.remove(toremove)
			for elem in heap:
				if elem[1]<=currentstars:
					elem=(elem[0],0,elem[2],elem[3])
	for i in range(0,N):
		if status[i]!=2:
			return -1
	return times

if __name__=="__main__":
	inpfile=open(sys.argv[1],'r')
	T=int(inpfile.readline())
	for i in range(0,T):
		N=int(inpfile.readline())
		levels=[]
		for j in range(0,N):
			levels.append([int(x) for x in inpfile.readline().split()])
		t=solvecase(N,levels)
		if t==-1:
			print('Case #'+str(i+1)+': Too Bad')
		else:
			print('Case #'+str(i+1)+':', t)
	inpfile.close()

			
