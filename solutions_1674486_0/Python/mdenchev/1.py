fin = open("A-small.in")
fout = open("1.out", "w")

caseCount = int(fin.readline())

def getNodesToX(nodes, x):
		leadnodes = []
		for j, node in enumerate(nodes):
			if node.count(x) > 0:
				leadnodes.append(j+1)
		return leadnodes

def writeSolution(f, case, solution):
	f.write("Case #{0}: {1}\n".format(case, solution))



for case in range(caseCount):
	print 1
	nodeCount = int(fin.readline())
	nodes = []
	done = False
	for node in range(nodeCount):
		nodes.append(map(int, fin.readline().split()[1:]))
	for i in range(1, nodeCount+1):
		if done: break
		leadnodes = getNodesToX(nodes, i+1)
		
		l = 1
		newleadnodes = leadnodes
		while len(leadnodes) > l:
			l = len(leadnodes)
			nld  = []
			for j in newleadnodes: nld += getNodesToX(nodes, j)
			newleadnodes = nld 
			leadnodes += newleadnodes
			print leadnodes
			
			#if len(set.intersection(set(leadnodes), set(newleadnodes))) > 0:
			if len(leadnodes) > len(set(leadnodes)):
				writeSolution(fout, case+1, 'Yes')
				done = True
				break
	if done == False:
		writeSolution(fout, case+1, 'No')

	print '----------'
