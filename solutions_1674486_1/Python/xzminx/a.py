import sys

parents = {}
paths = {}
grid = {}

def search(x, visited):
	if x in visited and visited[x]:
		return True
	visited[x] = True
	for nextt in parents[x]:
		if search(nextt, visited):
			return True
	return False

def solve(n):
	grid = {}
	for i in range(1, n+1):
		grid[i] = {}
	for i in parents:
		for j in parents[i]:
			grid[i][j] = set()
	for i in range(1, n+1):
		visited = {}
		visited[i] = True
		for p in parents[i]:
			if search(p, visited):
				return 'Yes'
	return 'No'



if __name__ == '__main__':
	sys.setrecursionlimit(100000000)
	fin = sys.stdin
	if len(sys.argv) > 1:
		fn = sys.argv[1]
		if fn != '-':
			fin = open(fn)
	fout = open('a.out', 'w')
	t = int(fin.readline())
	for i in range(t):
		n = int(fin.readline().strip())
		parents = {}
		paths = set()
		for j in range(n):
			g = fin.readline().strip().split(' ')
			for k in range(len(g)):
				g[k] = int(g[k])
			m = g[0]
			if m != 0:
				parents[j+1] = list(g[1:])
			else:
				parents[j+1] = list()
		ss = 'Case #%d:'%(i+1) + ' ' + solve(n)
		print ss
		fout.write(ss+'\n')
	fout.close()
