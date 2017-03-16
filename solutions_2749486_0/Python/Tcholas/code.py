#!/usr/bin/python

import heapq, math

def move(direction, units, pos):
	if direction == 'N':
		return (pos[0], pos[1] + units)
	elif direction == 'S':
		return (pos[0], pos[1] - units)
	elif direction == 'E':
		return (pos[0] + units, pos[1])
	elif direction == 'W':
		return (pos[0] - units, pos[1])

def expand(units, pos):
	return [(move('N', units, pos), 'N'),
			(move('S', units, pos), 'S'),
			(move('E', units, pos), 'E'),
			(move('W', units, pos), 'W')]

def pythagoras(pos1, pos2):
	return math.sqrt(math.pow(pos1[0] - pos2[0], 2) + math.pow(pos1[1] - pos2[1], 2))

def aStar(goal):
	pos = (0, 0)
	openPositions = []
	closedPositions = []
	map = {}
	distances = {}
	openPositions.append((1, pos))
	distances[pos] = 1
	
	while len(openPositions) > 0:
		(d, current) = openPositions.pop(0)
#		print current
		
		if current == goal:
#			print 'Reached goal'
			return map
			
		closedPositions.insert(0, current)
		
		for neighbor, direction in expand(distances[current], current):
			dist = 1 + distances[current]
			heuristic = pythagoras(goal, neighbor) + distances[current]
#			print dist, pythagoras(goal, neighbor), neighbor
			
			if neighbor in closedPositions:
				if dist >= distances[neighbor]:
					continue
			
			if neighbor not in openPositions or dist < distances[neighbor]:
				heapq.heappush(openPositions, (heuristic, neighbor))
				map[neighbor] = (current, direction)
				distances[neighbor] = dist
				
	print 'Failed'
	return False

def reconstructPath(map, pos):
	if map.has_key(pos):
		p = reconstructPath(map, map[pos][0])
#		print pos
		p.append(map[pos][1])
		return p
	else:
#		print pos
		return []

# Open file
fp = open('B-small-attempt1.in')
#fp = open('data.txt')
cases = int(fp.readline())
print '#Cases:', cases

# Open output file
fpout = open('output.txt', 'w')

for i in range(cases):
	node = [data for data in fp.readline().split()]
	goal = (int(node[0]), int(node[1]))
#	print 'Goal:', goal
	
	map = aStar(goal)
	path = ''.join(reconstructPath(map, goal))
#	print 'Path:', path
		
	print 'Case #%d: %s' %(i + 1, path)
	fpout.write('Case #%d: %s\n' %(i + 1, path))