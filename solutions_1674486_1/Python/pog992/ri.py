#!/usr/bin/env python
# -*- coding: utf-8 -*-

def rt(f):
	ws = ' \t\n'
	while True:
		c = f.read(1)
		if c not in ws: break
	l = [c]
	while True:
		c = f.read(1)
		if c in ws: break
		l.append(c)
	return ''.join(l)

def ri(f): return int(rt(f))
def rf(f): return float(rt(f))

from collections import deque

def bfs(G,v):
	visited = [False for u in G]
	#visited[v] = Fal
	d = deque([v])
	while d:
		u = d.pop()
		if visited[u]: return True
		else:
			visited[u] = True
			for x in G[u]:
				d.append(x)
	return False
	

def dia(G):
	for v in xrange(1, len(G)):
		if bfs(G,v): return True
	return False

from sys import stdin
t = ri(stdin)
for testcase in xrange(1, t+1):
	n = ri(stdin)
	G = [ [] for _ in xrange(n+1) ]
	for v in xrange(1,n+1):
		k = ri(stdin)
		for _ in xrange(k):
			G[v].append(ri(stdin))
	print "Case #%d: %s"%(testcase, "Yes" if dia(G) else "No")
	
