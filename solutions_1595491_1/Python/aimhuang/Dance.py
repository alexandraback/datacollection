#!/usr/bin/env python
from fractions import gcd
from sys import stdin
T=int(stdin.readline())
for case in range(1, T+1):
	t=map(int, stdin.readline().split())
	N=t.pop(0)
	S=t.pop(0) #surprising
	p=t.pop(0) #best result
	m=0   #number of best result
	if p==0:
		m=N
	elif p==1:
		for i in range(1,N+1):
			if t[i-1]>0:
				m+=1
	else:
		for i in range(1,N+1):
			average=t[i-1]/3
			r = t[i-1]%3
			if p>average+2:
				continue
			if (p<=average) or (p==average + 1 and r):
				m+=1
				continue
			if (p>average+1) and (r<2):
				continue	
			if S>0:
				S-=1
				m+=1
			
			#switch(r):
				#case 0:
					#if p>average+1:
						#continue
					#else:
						#if S>0:
							#S-=1
							#m+=1
					#break
				#case 1:
					#if p>average+1:
						#continue
					#else:
						#m+=1				
					#break
				#case 2:
					#if p==average+1:
						#m+=1
						#continue
					#elif p==average+2:
						#if S>0:
							#S-=1
							#m+=1
					#break
					



	print "Case #%d:"%case, m
