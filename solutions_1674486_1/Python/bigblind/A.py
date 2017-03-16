from __future__ import division

import itertools
inp = open('A.in')
out = open('A.out','w')
cases = int(inp.readline())



for case in xrange(1,cases+1):
	classes = int(inp.readline())
	inheritance = {}
	for klass in xrange(1,classes+1):
		inheritance[klass] = [int(x) for x in inp.readline().split(" ")[1:]]
	
	broken = False
	
	for klass in inheritance:
		if len(inheritance[klass]) > 1:
			visited = []
			tovisit = list(inheritance[klass])
			while not len(tovisit) == 0:
				current = tovisit.pop()
				visited.append(current)
				for node in inheritance[current]:
					if node in visited or node in tovisit:
						broken = True
						break
					else:
						tovisit.append(node)
				if broken:
					break
		
	if broken:
		statement = "Yes"
	else:
		statement = "No"
	
	out.write("Case #"+str(case)+": "+statement+"\n")