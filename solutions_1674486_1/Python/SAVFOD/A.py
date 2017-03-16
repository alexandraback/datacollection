black = 1
white = 0
grey = 2

import copy
import sys
sys.setrecursionlimit(10000)

def symmetrize(or_graph):
	graph_copy = copy.deepcopy(or_graph)
	for i in xrange(0, len(graph_copy)):
		for j in graph_copy[i]:
			or_graph[j].append(i)
	
def push_forward_ok(vertexes, or_graph, pos):
	
	#print vertexes
	#print or_graph
	#print pos
	
	
	if vertexes[pos] == black:
		return False
		
	#for i in or_graph[pos]:
	#	print i
	vertexes[pos] = black		
	for i in or_graph[pos]:
		if not push_forward_ok(vertexes, or_graph, i):
			return False
	return True
	

def has_cycle(graph):
	
	
	for i in xrange(0, len(graph)):
		vertexes = []
		for j in xrange(0, len(graph)):
			vertexes.append(white)
		
		#print vertexes[i]
		if not push_forward_ok(vertexes, graph, i):
			return True
			
	return False
	
	
	
	



f = open('A.in', "r")
res = open('A.txt', "w")
T = int(f.readline())
for line in xrange(0,T):
	N = int(f.readline())
	
	graph = []
	
	for point in xrange(0, N):
		
		s = f.readline()
		s_numbers = s.split()
		arcs_count = int(s_numbers[0])		
		
		arcs = []
		for pos in xrange(0, arcs_count):
			arcs.append(int(s_numbers[pos + 1]) - 1)
		
		graph.append(arcs)
		
		
	#symmetrize(graph)
	
	if has_cycle(graph):
		answer = "Yes"
	else:
		answer = "No"

	
	res.write('Case #' + str(line + 1) + ': ' + answer + '\n')

