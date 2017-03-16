#!/usr/bin/env python
from sys import stdin
T=int(stdin.readline())




def exchangeB(n, B):
	sn=str(n)
	fn=int(sn[0])
	ln=len( sn )
	fB=int( str(B)[0] )
	j=[]
	for k in range(1, ln):
		kn=int( sn[k] )
		if kn < fn or (kn > fB):
			continue
		if kn > fn and kn < fB:
			j.append( sn[k:]+sn[0:k] )
			continue
		m=int( sn[k:]+sn[0:k] )
		if m > n and m<=B:
			j.append(m)
	return len(set(j))



for case in range(1, T+1):
	A,B=map(int, stdin.readline().split())
	n=A
	y=0
	while(n<B):
		y+=exchangeB(n, B)
		n+=1
		
	print "Case #%d:"%case, y
