#!/usr/bin/python

import Queue
import sys

T = int(raw_input())

for i in range(T):
	N = int(raw_input())
	M = [0 for x in range(N + 1)]
	edge = [0 for x in range(N + 1)]
	
	for j in range(N):
		inp = raw_input().split()
		M[j + 1] = int(inp[0])
		edge[j + 1] = []
		for k in range(M[j + 1]):
			edge[j + 1].append(int(inp[k + 1]))

	flag = 0
	
	for j in range(N):
		nodes = [x + 1 for x in range(N)]
		node = j + 1
		q = Queue.Queue()
		q.put(node)
		while not q.empty():
			node = q.get()
			if node not in nodes:
				flag = 1
				break
			nodes.remove(node)
			for j in range(M[node]):
				q.put(edge[node][j])
		if flag == 1:
			break

	if flag == 1:
		sys.stdout.write("Case #%d: Yes" % (i + 1))
	else:
		sys.stdout.write("Case #%d: No" % (i + 1))
	print ""
