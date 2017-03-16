from collections import defaultdict
import queue

def solveIt(end):
	places = queue.Queue()
	visited = defaultdict(bool)
	places.put((0,0,1))
	visited[(0,0,1)] = True
	parents = {}
	parents[(0,0,1)] = None
	while not places.empty():
		spot = places.get()
		if ((spot[0], spot[1]) == end):
			parent = parents[spot]
			s=""
			while (parent != None):
				if (parent[0] < spot[0]):
					s = "E"+s
				elif (parent[0] > spot[0]):
					s = "W"+s
				elif (parent[1] < spot[1]):
					s = "N"+s
				else:
					s = "S"+s
				spot = parent
				parent = parents[spot]

			return s
		jump = spot[2]
		arr = []
		arr.append((spot[0] - jump, spot[1], jump+1))
		arr.append((spot[0] + jump, spot[1], jump+1))
		arr.append((spot[0], spot[1] - jump, jump+1))
		arr.append((spot[0], spot[1] + jump, jump+1))
		for p in arr:
			if not visited[p]:
				visited[p] = True
				parents[p] = spot
				places.put(p)

tests = int(input())
for i in range(1, tests+1):
	st = input().split(" ")
	x = int(st[0])
	y = int(st[1])
	print("Case #" + str(i) + ": " + solveIt((x,y)))
