output=[]
v=[]

import math
import sys

def readInput():
	
	f = open('B-small-attempt1.in', 'r')
	fo = open('final.txt', 'w')
	T = int(f.readline())

	for num in range(1,int(T)+1):
		
	
		cl = f.readline()
		X= int(list(cl.strip('\n').split(' '))[0])
		Y= int(list(cl.strip('\n').split(' '))[1])
		
		#if not num==3 : 
		#	continue
		path = ''
		CX=0
		CY=0
	
		if X>0:
			to_add='WE'*X
		else:
			to_add='EW'*abs(X)
		
		path+=to_add

		if Y>0:
			to_add='SN'*Y
		else:
			to_add='NS'*abs(Y)
		path+=to_add
		print len(path)
		fo.write('Case #'+str(num)+': '+path+'\n')
			
readInput()

