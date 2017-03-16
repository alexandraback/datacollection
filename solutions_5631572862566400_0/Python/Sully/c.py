'''
4
4
2 3 4 1
4
3 3 4 1
4
3 3 4 3
10
7 8 10 10 9 2 9 6 3 3
'''

import sys
from collections import defaultdict

f = open(sys.argv[1],'r')
num = int(f.readline())


#from http://stackoverflow.com/questions/29320556/finding-longest-path-in-a-graph, creative commons
def DFS(G,v,seen=None,path=None):
	if seen is None: seen = []
	if path is None: path = [v]

	seen.append(v)

	paths = []
	for t in G[v]:
		if t not in seen:
			t_path = path + [t]
			paths.append(tuple(t_path))
			paths.extend(DFS(G, t, seen, t_path))
	return paths


def solve(n):
	bfflist = f.readline().strip('\n').split(' ')
	maxpath = 0
	#s is a string of numbers.  Represent s as a graph, where node index(s) points to node s[index(s)]	
	edges = []

	for i in xrange(len(bfflist)):
		kid = i+1
		bff = int(bfflist[i])
		edges.append([kid,bff])

	G = defaultdict(list)
	G2 = defaultdict(list)
	for (s,t) in edges:
		G[s].append(t)
#		G[t].append(s)

#	print 'edges'
#	print edges

#	print 'paths'
	#print DFS(G,1)
	#print DFS(G,2)
	#print DFS(G,3)
	#print DFS(G,4)

	maxlen = 0

	for i in range(len(bfflist)):
		all_paths = DFS(G,i+1)
		max_path  = max(all_paths, key=lambda l: len(l))
		max_path = list(max_path)
		if len(max_path) < maxlen:
			continue
		last = max_path[-1]
		secondlist = max_path[-2]
		first = max_path[0]
		if [last,first] not in edges and [last,secondlist] not in edges :
			max_path.pop(-1)
#		print last-1
#		print edges
#		print edges[3]
		if [last,secondlist] in edges:
			found = 0
			for i in range(len(bfflist)):
				j = i+1

				if j not in max_path:
#					print j
					if [j,last] in edges:
						max_path.append(j)
						break

		if len(max_path)>maxlen:
#			print max_path
			maxlen=len(max_path)


	

	return str(maxlen)
		

for i in xrange(1,num+1):
	print 'Case #'+str(i)+': '+ solve(f.readline().strip('\n'))


