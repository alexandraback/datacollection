#!/usr/bin/env python2
from heapq import *
from collections import defaultdict
for t in xrange(1,1+int(raw_input())):
	n,m=map(int,raw_input().split())
	code=[raw_input().rstrip('\r\n')for _ in xrange(n)]
	g=defaultdict(list)
	for _ in xrange(m):
		x,y=map(int,raw_input().split())
		g[x-1].append(y-1)
		g[y-1].append(x-1)
	print"Case #%d:"%t,
	ans=""
	seen=set()
	q=[(code[0],0)]
	while q:
		suffix,u=heappop(q)
		if u in seen:
			continue
		seen.add(u)
		ans+=suffix
		for v in g[u]:
			heappush(q,(code[v],v))
	print ans
