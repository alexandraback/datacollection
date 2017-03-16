import sys
from collections import defaultdict,Counter
import pycosat

caseCount = int(sys.stdin.readline().strip())
for c in range(caseCount):
	termCount = int(sys.stdin.readline().strip())

	nodeCount = 0
	nodeLookup1 = {}
	nodeLookup2 = {}
	edges = []

	for t in range(termCount):
		terms = sys.stdin.readline()
		t1,t2 = terms.split(' ')

		if t1 in nodeLookup1:
			n1 = nodeLookup1[t1]
		else:
			nodeCount += 1
			n1 = nodeCount
			nodeLookup1[t1] = n1
		if t2 in nodeLookup2:
			n2 = nodeLookup2[t2]
		else:
			nodeCount += 1
			n2 = nodeCount
			nodeLookup2[t2] = n2

		edges.append((n1,n2))
	#print edges

	clauses = defaultdict(list)
	negatives = []
	for i,(n1,n2) in enumerate(edges):
		clauses[n1].append(i+1)
		clauses[n2].append(i+1)
		negatives.append([-(i+1)])

	#finalClauses = clauses.values() + negatives
	#print finalClauses

	#result = pycosat.solve(clauses.values())
	#print result
	#for sol in pycosat.itersolve(clauses.values()):
	#	negCount = sum ( [ i<0 for i in sol ] )
	#	print negCount

	negCounts = [ sum ( [ i<0 for i in sol ] ) for sol in pycosat.itersolve(clauses.values()) ]
	result = max(negCounts)
	print "Case #%d: %d" % (c+1,result)

