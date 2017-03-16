#! /usr/bin/env python3
'''
' Title:	
' Author:	Cheng-Shih, Wong
' Date:		
'''

def calcCycleLen( u, nxt, vis ):
	l = 0
	while u not in vis:
		vis.add(u)
		u = nxt[u]
		l += 1
	return l

def findCycle( pre, u, l, nxt, vis, mp ):
	v = nxt[u]

	if v==pre: 
		if v not in mp: mp[v] = l
		else: mp[v] = max(mp[v],l)
		return l
	if v in vis: 
		nvis = set()
		return calcCycleLen( u, nxt, nvis )
	
	vis.add(v)
	return findCycle( u, v, l+1, nxt, vis, mp )

t = int(input())

for ti in range(1,t+1):
	n = int(input())
	nr = range(1,n+1)
	fri = {}
	
	for i, v in enumerate(input().split()):
		v = int(v)
		fri[i+1] = v

	maxl = 0
	mp = {}

	for i in nr:
		vis = set([i])
		l = findCycle( -1, i, 1, fri, vis, mp )
		maxl = max(l,maxl)
	
	suml = 0
	for u in nr:
		v = fri[u]
		if u!=fri[v]: continue
		if u > v: continue
		suml += mp[u]+mp[v]-2
	
	maxl = max(maxl,suml)
	
	print( 'Case #{0}: {1}'.format(ti,maxl) )
