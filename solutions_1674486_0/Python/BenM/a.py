import sys

inputTxt = sys.stdin.readlines()

#print inputTxt

cases = []

def getChild(nodes, n):
	if len(n):
		nod = set()
		for g in n:
			moreNodes, inter = getChild(nodes, nodes[g])
			if inter or nod & moreNodes:
				return set(), True
			nod = nod | moreNodes
		if n & nod:
			return set(), True
		else:
			return n | nod, False
	else:
		return set(), False

count = 1
i = 1
while i < len(inputTxt):
	N = int(inputTxt[i])
	classes = inputTxt[i + 1:i + 1 + N]
	
	nodes = [set() for g in classes]
	for classNum , Ni in enumerate(classes):
		for links in map(int, Ni.split()[1:]):
			nodes[links-1].add(classNum)
	
	answer = False		
	for n in nodes:
		if len(n) > 1:
			o, answer = getChild(nodes, n)
			if answer:
				break
			#print n, getChild(nodes, n)
		
	#print nodes
	i += N + 1
	
	print "Case #{}: {}".format(count, "Yes" if answer else "No")
	count+=1
	



