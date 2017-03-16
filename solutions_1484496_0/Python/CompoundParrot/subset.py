#!/usr/bin/env python
# encoding: utf-8
"""
CODEJAM TEMPLATE

Created by Jamie Smith


"""

import sys
import os
from numpy import *
	
def readints(f):
	return map(int, f.readline().split())


def main():
	os.chdir("/Users/Jamie/Documents/Codejam")
	
	f=open('input.txt','r')
	f=open('C-small-attempt0.in','r')
	# f=open('A-large.in','r')
	o=open('subset.txt','w')
	
	T=int(f.readline())

	for j in range(T):
		print j
		L=readints(f)
		N=L.pop(0)
		S=sum(L)
		
		A=[]
		for k in range(N):
			A.append([0 for i in range(S+1)])
			
		A[0][L[0]+S/2]=[1]
		A[0][-L[0]+S/2]=[-1]	
		for k in range(1,N):
			for i in range((S+1)):
				if A[k-1][i]!=0:
					A[k][i]=A[k-1][i]+[0]
				elif i-L[k]>=0 and A[k-1][i-L[k]]!=0:
					A[k][i]=A[k-1][i-L[k]]+[1]
				elif i+L[k]<=S and A[k-1][i+L[k]]!=0:
					A[k][i]=A[k-1][i+L[k]]+[-1]
		
		if A[-1][S/2]==0:
			result="Impossible"
		else:
			X=[]
			Y=[]
			for r in range(N):
				q=A[-1][S/2][r]
				if q==1:
					X.append(L[r])
				elif q==-1:
					Y.append(L[r])
		# print X, sum(X)
		# print Y, sum(Y)
		
		o.write("Case #%s:\n" % (j+1))
		s=''
		for x in X:
			s=s+' '+str(x)
		o.write(s+'\n')
		s=''
		for y in Y:
			s=s+' '+str(y)
		o.write(s+'\n')
		
	f.close()
	o.close()

if __name__ == '__main__':
	main()


