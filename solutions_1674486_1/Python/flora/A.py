from collections import deque

def hasDiamondInheritance(adjMatrix, i):
	paths = []
	queue = deque([i])
	while(len(queue)>0):
		n = queue.popleft()
		for j in adjMatrix[n]:
			if j!=i:
				if j in paths:
					return True
				else:
					queue.append(j)
					paths.append(j)
	return False

ncases = int(raw_input())
for c in range(0,ncases):
	adjMatrix = []
	N = int(raw_input())
	for i in range(0,N):
		edgesInfo = [int(x)-1 for x in raw_input().split()]
		adjMatrix.append(edgesInfo[1:])
	allpaths = []
	hasDiamond = False
	for i in range(0,N):
		if (hasDiamondInheritance(adjMatrix,i)):
			hasDiamond = True
			break
	if hasDiamond:
		print "Case #{0}: Yes".format(c+1)
	else:
		print "Case #{0}: No".format(c+1)

