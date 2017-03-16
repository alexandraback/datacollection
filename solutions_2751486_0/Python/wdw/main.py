output=[]
v=[]

import math
import sys
v=['a', 'e', 'i', 'o', 'u']

def find_index(a,n,S):
	b=a
	i =a
#	not_found = True
	num =0
	while i< len(S):# and not_found:

		if(not S[i] in v):
			num+=1
		else:
			num=0
		#print i,num,n
		if(num == n):
			return i
		i+=1
	return -1
def readInput():
	
	f = open('A-small-attempt0.in', 'r')
	fo = open('final.txt', 'w')
	T = int(f.readline())

	for num in range(1,int(T)+1):
		

		cl = f.readline()
		S= (list(cl.strip('\n').split(' '))[0])
		N= int(list(cl.strip('\n').split(' '))[1])
		#if not num==3 : 
		#	continue
		last_index =0 
		sum=0
		index =0
		while not index==-1:			
			
			index = find_index(last_index,N,S)-N+1
			#print index,S,N
			if (index <0):
				break
			#index+=1 # adjustment for arrays	
			#if(last_index>0):last_index-=1
			before = ((index)-last_index)*(len(S)-index-N+1)
			after = (len(S)-index-N+1) 
			sum+= before + after
			#print index,sum, before, after
			last_index = index +1
		#print "sum = "+str(sum)	
		fo.write('Case #'+str(num)+': '+str(sum)+'\n')
			
readInput()

