#!/usr/bin/env python

import numpy as np
import sys

def password(A,B,P):
	expect=np.zeros(A+1)
	p_allcorrect=np.ones(A+1)
	for i in range(1,A+1):
		p_allcorrect[i]=p_allcorrect[i-1]*P[i-1]
	for i in range(0,A+1): #delete i char
		expect[i]=(B-A+2*i+1)*p_allcorrect[A-i]+(1-p_allcorrect[A-i])*(B-A+2*i+B+2)
	minval=np.min(expect)
	if minval>B+2:
		return float(B+2)
	else:
		return minval

if __name__=="__main__":
	inpfile=open(sys.argv[1],'r')
	T=int(inpfile.readline())
	for i in range(0,T):
		inpline=inpfile.readline()
		inp=[int(x) for x in inpline.split()]
		inpline=inpfile.readline()
		inp2=[float(x) for x in inpline.split()]
		print('Case #'+str(i+1)+': %.6f'%password(inp[0],inp[1],inp2))
	inpfile.close()


