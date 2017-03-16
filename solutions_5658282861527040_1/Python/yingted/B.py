#!/usr/bin/env python2
import numpy as np
from sys import stderr as err
def allpairs(k):#a=b=xxxxx
	if k=='':
		return 1
	if k[0]=='0':
		return allpairs(k[1:])*3
	else:
		return 4**(len(k)-1)*3+allpairs(k[1:])
def count(a,b,k):
	assert len(a)==len(b)==len(k)
	if len(a)==0:
		return 1
	if k=='1'*len(k):#anything
		return(int(a,2)+1)*(int(b,2)+1)
	if a=='1'*len(a)and b=='1'*len(b):
		return allpairs(k)
	nl=len(a)-1
	xxxxx='1'*nl
	allofthem=2**nl
	if a[0]=='0':
		if b[0]=='0':
			if k[0]=='0':
				return count(a[1:],b[1:],k[1:])
			else:
				return count(a[1:],b[1:],xxxxx)
		else:
			if k[0]=='0':
				return count(a[1:],xxxxx,k[1:])\
				      +count(a[1:],b[1:],k[1:])
			else:
				return count(a[1:],xxxxx,xxxxx)\
				      +count(a[1:],b[1:],xxxxx)
	else:
		if b[0]=='0':
			return count(b,a,k)
		else:
			if k[0]=='0':
				return count(xxxxx,xxxxx,k[1:])\
				      +count(xxxxx,b[1:],k[1:])\
				      +count(a[1:],xxxxx,k[1:])
			else:
				return count(xxxxx,xxxxx,xxxxx)\
				      +count(xxxxx,b[1:],xxxxx)\
					  +count(a[1:],xxxxx,xxxxx)\
					  +count(a[1:],b[1:],k[1:])
for t in xrange(1,1+int(raw_input())):
	a,b,k=map(int,raw_input().split())
	a=bin(a-1)[2:]
	b=bin(b-1)[2:]
	k=bin(k-1)[2:]
	n=max(len(a),len(b),len(k))
	a=(n-len(a))*'0'+a
	b=(n-len(b))*'0'+b
	k=(n-len(k))*'0'+k
	print'Case #%d:'%t,
	#print>>err,'A <= %s and B <= %s and A&B <= %s'%(a,b,k)
	print count(a,b,k)
