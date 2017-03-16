import os, sys

inFile = None
outFile = None

def printAnswer(case, answer):
	outFile.write('Case #{0}: {1}\n'.format(case+1, answer))

def dfs(v, vis, graph):
	if vis[v]:
		return True

	vis[v] = True

	for x in graph[v]:
		if dfs(x, vis, graph):
			return True

	return False


def solveCase(caseNo):
	n = int(inFile.readline().strip())
	g = []
	for k in xrange(n):
		list = map(int, inFile.readline().strip().split()[1:])
		g.append([i-1 for i in list])

	# print g
	
	for i in xrange(n):
		vis = (n+1) * [False]
		if dfs(i, vis, g):
			printAnswer(caseNo, 'Yes')
			return

	printAnswer(caseNo, 'No')



def main():
	cases = int(inFile.readline().strip())
	for case in range(cases):
		solveCase(case)

if __name__ == '__main__':
	inFile = open('in.txt','rt')
	outFile = open('out.txt', 'wt')
	main()