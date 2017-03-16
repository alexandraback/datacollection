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
	
	# f=open('input.txt','r')
	# f=open('A-small-attempt1.in','r')
	f=open('A-large.in','r')
	o=open('safety.txt','w')
	
	T=int(f.readline())

	for j in range(T):
		L=readints(f)
		N=L.pop(0)
		X=sum(L)
		
		R=[0 for i in range(N)]
		
		V=[True for l in L]
		ok=False
		X2=float(X)
		N2=N
		while not(ok) and N2>1:
			ok=True
			Q=float(X2+X)/N2
			for k in range(N):
				if L[k]>=Q and V[k]:
					ok=False
					V[k]=False
					X2-=L[k]
					N2-=1

		
		
		Q=float(X2+X)/(N2*X)
		for k in range(N):
			if V[k]:
				R[k]=100*(Q-float(L[k])/X)

		s=''
		for k in range(N):
			s=s+' '+str(R[k])
		
		 # print "Case #%s: %s\n" % (j+1,result)
		o.write("Case #%s: %s\n" % (j+1,s))
	f.close()
	o.close()

if __name__ == '__main__':
	main()


