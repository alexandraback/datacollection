import sys
import optparse

debug = True

def make_graph(N,S):
	graph = [[] for x in range(N)]
	for i in range(N):
		if not i in graph[S[i]]:
			graph[S[i]].append(i)
		if not S[i] in graph[i]:
			graph[i].append(S[i])
	
	if debug:
		print '[+] make_graph %s' % str(graph)
	return graph

"""
def check_count(graph,k,i):

def remove_graph(graph,i):
	count = -1
	minindex
	for k in range(len(graph[i])):
		tmp = check_count(graph,k,i)
		if count > tmp:
			count = tmp
			minindex = k

	graph[graph[i][k]].remove()
	graph[i].remove(k)
"""


def dfs(graph,visited,i):
	ret = 1
	if visited[i] == True:
		return 0
	
	visited[i] = True

	for k in range(len(graph[i])):
		ret += dfs(graph, visited, graph[i][k])

	return ret

def solve(data):
	N = data[0]
	S = data[1]
	if debug:
		print '[+] input data %d %s' % (N, str(S))

	graph = make_graph(N,S)

	minus = 0
	for i in range(N):
		if len(graph[i]) > 2:
			minus += len(graph[i]) -2
	
	ret = 0
	visited = [False for x in range(N)]
	for i in range(N):
		if visited[i] == True:
			continue
		ret = max(dfs(graph,visited,i),ret)
	ret -= minus
	return ret

def readData(infile):
	N = int(infile.readline().strip())
	S = map(int, infile.readline().strip().split())
	for i in range(N):
		S[i] = S[i] -1
	return N, S

def howto():
	usage = ' -i <input file> [-o <output file>]'
	parser = optparse.OptionParser(sys.argv[0] + usage)
	parser.add_option(
		'-i', dest='infile', type='string', help='specify infile name')
	parser.add_option(
		'-o', dest='outfile', type='string', help='specify outfile name')
	(options, args) = parser.parse_args()
	if options.infile is None:
		print parser.usage
	return options.infile, options.outfile

if __name__ == '__main__':
	infile, outfile = howto()
	if infile is None:
		exit()

	infile = open(infile, 'r')
	if outfile is not None:
		outfile = open(outfile, 'w')

	T = int(infile.readline().strip())
	for caseN in xrange(1, T + 1):
		data = readData(infile)
		result = solve(data)
		resultForm = 'Case #%i: %s\n' % (caseN, result)

		if outfile:
			outfile.write(resultForm)
		else:
			print resultForm

	infile.close()
	if outfile is not None:
		outfile.close()
