# http://code.google.com/codejam/contest/4314486/dashboard#s=p1
from collections import defaultdict
from re import match
from numpy import array, argsort
from time import sleep
from numpy.linalg import matrix_rank
from igraph import Graph

def adjlist_find_paths(a, n, m, path=[]):
  "Find paths from node index n to m using adjacency list a."
  path = path + [n]
  if n == m:
    return [path]
  paths = []
  for child in a[n]:
    if child not in path:
      child_paths = adjlist_find_paths(a, child, m, path)
      for child_path in child_paths:
        paths.append(child_path)
  return paths

def paths_from_to(graph, source, dest):
  "Find paths in graph from vertex source to vertex dest."
  a = graph.get_adjlist()
  n = source
  m = dest
  return adjlist_find_paths(a, n, m)


def check(sol, paths):
	graph = Graph.Adjacency(sol)
	graph = graph.as_directed()
	if not len(paths_from_to(graph, 0, len(sol)-1))==paths:
		print("ERROR")

def Rn(buildings):
	res = []
	for n in range(buildings):
		line = [0]*(n+1) + [1]*(buildings-n-1)
		res.append(line)
	return res

def read_file(fname):
	res = []
	with open(fname,"r") as f:
		data = [l.strip() for l in f.readlines()][1:]
		for p in data:
			res.append(list(map(int, p.split(" "))))
	return res

def solve_all(fname):
	problems = read_file("%s.in" % fname)
	case = 1
	text = ""
	for B, M in problems:
		print("Solving Case #%s" % case)
		res = solve(B, M)
		text += "Case #%s: %s\n" % (case, res)
		case+=1
	with open("%s.out" % fname, "w") as out:
		out.write(text)

def solve(buildings, paths):
	max_paths = 2**(buildings-2)
	if paths > max_paths:
		return "IMPOSSIBLE"
	elif paths == max_paths:
		res = Rn(buildings)
	elif paths < max_paths:
		binary = [int(l) for l in "{0:b}".format(paths)]
		zero_pad = buildings-len(binary)-1
		res = [[0]*buildings for _ in range(zero_pad-1)]
		for k, line in enumerate(res):
			line[k+1] = 1
		res.append([0]*zero_pad+binary+[0])
		res.extend([[0]*zero_pad+l for l in Rn(len(binary)+1)])
	#check(res, paths)
	res = "\n".join("".join(map(str,l)) for l in res)
	return "POSSIBLE\n"+res


solve_all("large")