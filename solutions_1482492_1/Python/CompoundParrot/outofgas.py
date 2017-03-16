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
	# f=open('B-small-attempt1.in','r')
	f=open('B-large.in','r')
	o=open('gas.txt','w')
	
	T=int(f.readline())

	for j in range(T):
		o.write("Case #%s:\n" % (j+1))
		print 'Case ',j+1
		L=f.readline().split()
		D=float(L.pop(0))
		N=int(L.pop(0))
		A=int(L.pop(0))
		
		C=[]
		for k in range(N):
			C.append(map(float, f.readline().strip().split()))
			

		Acc=map(float,f.readline().strip().split())
			
		for a in Acc:
			
			t0=C[0][0]
			x0=C[0][1]
			y=float(0)
			u=float(0)
			
			if N==1:
				t0=t0+(-u+sqrt(u**2-2*a*(y-D)))/a
			
			for i in range(1,N):
				if y==D:
					break
				t1=C[i][0]
				x1=C[i][1]
				v=(x1-x0)/(t1-t0)
				if x1<D:
					
					if (u-v)**2-2*a*(y-x0)>=0:
						tint=t0+(v-u-sqrt((u-v)**2-2*a*(y-x0)))/(a)
						if tint<=0:
							tint=t0+(v-u+sqrt((u-v)**2-2*a*(y-x0)))/(a)
					else:
						tint=float('Infinity')
					if tint<=t1:
						y=x1
						u=v
						t0=t1
						x0=x1
					else:
						y=y+u*(t1-t0)+(a*(t1-t0)**2)/2
						u=u+a*(t1-t0)
						t0=t1
						x0=x1
				else:
					t1=t0+(D-x0)/v
					x1=D
					# if y==x0:
					# 						tint=t0
					if (u-v)**2-2*a*(y-x0)>=0:
						tint=t0+(v-u-sqrt((u-v)**2-2*a*(y-x0)))/(a)
						
						if tint<=t0:
							tint=t0+(v-u+sqrt((u-v)**2-2*a*(y-x0)))/(a)
					else:
						tint=float('Infinity')


					if tint<=t1:
						y=x1
						u=v
						t0=t1
						x0=x1
					else:
						t0=t0+(-u+sqrt(u**2-2*a*(y-D)))/a
						y=D
						# y=y+u*(t1-t0)+(a*(t1-t0)**2)/2
						# 						u=u+a*(t1-t0)
						# 						t0=t1
						# 						x0=x1

			o.write("%s\n" % (t0))
			# print t0

	f.close()
	o.close()

if __name__ == '__main__':
	main()


