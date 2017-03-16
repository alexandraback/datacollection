#!/usr/bin/python
from collections import defaultdict
from itertools import permutations

def readint ():
	return int(input())
def readarray ( f ):
	return map(f, input().split())

def solve(cities, paths):
	c2 = map(lambda x: x[1], sorted([(cities[i], i) for i in range(len(cities))]))
	poss = list(permutations(c2))
	for p in poss:
		valid = True
		open = [p[0]]
		for v in p[1:]:
			while len(open) > 0:
				if open[-1] in paths[v]:
					open.append(v)
					break
				del open[-1]
			else:
				valid = False
				break
		if valid:
			return "".join(map(lambda i: str(cities[i]), p))

cases = readint()
for k in range(cases):
	N,M = readarray(int)
	cities = []
	for i in range(N):
		cities.append(readint())
	paths = defaultdict(list)
	for i in range(M):
		a,b = readarray(int)
		paths[a-1].append(b-1)
		paths[b-1].append(a-1)
	print('Case #' + str(k+1) + ': ' + str(solve(cities, paths)))
