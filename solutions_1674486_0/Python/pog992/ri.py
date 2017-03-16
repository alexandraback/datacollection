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


def dfs(G,v):
	visited = [False for u in G]
	def step(v):
		visited[v] = True
		for u in G[v]:
			if visited[u]: return True
			else:
				if step(u): return True
		return False
	return step(v)

def dia(G):
	for v in xrange(1, len(G)):
		if dfs(G,v): return True
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
	
