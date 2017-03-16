from itertools import combinations
import math
from time import time


def solve(solver, fname_in, fname_out=None):
    if fname_out is None:
		fname_out = ''.join([fname_in, '.out'])
    fname_in = ''.join([fname_in, '.in'])
		
    with open(fname_in, 'r') as fin, open(fname_out, 'w') as fout:
		T = int(next(fin).strip())
		for case_n in xrange(1, T+1):
			case = read_case(fin)
			result = solver(case)
			write_case(fout, case_n, result)

def read_case(f):
	N = int(next(f).strip()) # class_count
	graph = dict()
	
	for class_n in xrange(1, N+1):
		line = map(int, next(f).split())
		graph[class_n] = set(line[1:])
		
	return graph

def write_case(f, i, res):
	if res:
		res = 'Yes'
	else:
		res = 'No'
	f.write('Case #{0}: {1}\n'.format(i, res))

################################################################################

def solve_small(graph):
	for node in graph:
		ways = list(find_ways(node, graph))
		if len(set(ways)) != len(ways):
			return True
	
	return False
	

def find_ways(from_, graph):
	for node in graph[from_]:
		yield node
		for node_ in find_ways(node, graph):
			yield node_




t = time()
solve(solve_small, 'a')

print time() - t















