t = int(raw_input())

from collections import Counter
import itertools
import sys

import networkx as nx


def dfs(g,s,excl1,excl2):
	md = 0
	for next in g[s]:
		if next!=excl1 and next!=excl2:
			md = max(md,dfs(g,next,excl1,excl2))
	return md+1




def solve(x):
	x= [0] + x
	rx = [[] for i in range(len(x))]

	for i in range(1,len(x)):
		rx[x[i]].append(i)

	vis =[0] *len(x)


	g = nx.DiGraph([(i,x[i]) for i in range(1,len(x))])
	ans = 0

	for s in nx.strongly_connected_components(g):
		ans = max(ans,len(s))

		if len(s) != 1 and len(s)!=2:
			for item in s:
				vis[item] = 1

	pairs = 0

	s1 = []
	s2 = []
	for i in range(1,len(x)):
		if x[x[i]] == i and not vis[i]:
			pairs +=1
			vis[i] = vis[x[i]] = 1
			l = dfs(rx,i,i,x[i]) -1 
			r = dfs(rx,x[i],i,x[i]) - 1
			s1.append(l)
			s2.append(r)

	if pairs>0:
		ans = max(ans, pairs *2 + sum(s1) + sum(s2))
	return ans 




for i in range(t):
	n = int(raw_input())
	xs = [int(x) for x in raw_input().split()] 
	print 'Case #{}: {}'.format(i+1,solve(xs))




