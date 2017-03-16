import sys

sys.setrecursionlimit(10000)

T = input()

def bfs(x):
	global nadj
	global adj
	global used
	if (used[x]): return True
	used[x] = True
	for i in adj[x]:
		if (bfs(i)): return True
	return False
	
for t in range(1, T+1):
	n = input()
	used = [False]*n
	nadj = [0]*n
	pai = []
	adj = []
	for i in range(0, n):
		pai.append(i)
		adj.append([])
	for i in range(0, n):
		line = raw_input()
		line = line.split()
		nadj[i] = int(line[0])
		for to in line[1:]:
			adj[i].append(int(to)-1)
	last = 0
	flag = False
	for i in range(0, n):
		used = [False]*n
		if (bfs(i)): 
			flag = True
			break

	if (flag): print 'Case #%d: Yes' % t
	else: print 'Case #%d: No' % t
