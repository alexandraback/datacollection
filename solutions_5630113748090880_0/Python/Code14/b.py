#! /usr/bin/env python3
'''
' Title:	
' Author:	Cheng-Shih, Wong
' Date:		
'''


t = int(input())

for ti in range(1,t+1):
	n = int(input())

	cnt = {}
	for i in range(2*n-1):
		ls = [int(v) for v in input().split()]
		
		for v in ls:
			if v not in cnt: cnt[v]=1
			else: cnt[v] += 1
	
	remain = []

	for u, v in cnt.items():
		if (v&1) == 1: remain.append(u)
	
	remain = sorted(remain)

	print( 'Case #{0}:'.format(ti),' '.join(str(v) for v in remain) )
