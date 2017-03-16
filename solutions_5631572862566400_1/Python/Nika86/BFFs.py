#! /usr/bin/python

T = int(raw_input())

def maxDepth(tree, node):
	if len(tree[node]) == 0:
		return 1
	
	d = 1
	for child in tree[node]:
		d = max(d, 1 + maxDepth(tree, child))

	return d

for t in range(1, T+1):

	N = int(raw_input())
	bff = [int(inp) - 1 for inp in raw_input().split()]

	tree = [[] for _ in range(N)]
	for i in range(N):
		if bff[bff[i]] != i:
			tree[bff[i]] += [i]

	longestCycle = 0
	longestPatch = 0

	for i in range(N):
		
		cur = i
		for _ in range(N + (N % 2)):
			cur = bff[cur]

		visited = set()
		cycleLength = 0

		while (cur not in visited):
			visited.add(cur)
			cur = bff[cur]
			cycleLength += 1

		if (cycleLength == 2) and (cur == i):
			longestPatch += maxDepth(tree, i)

		longestCycle = max(longestCycle, cycleLength)

	print 'Case #' + str(t) + ': ' + str(max(longestCycle, longestPatch))