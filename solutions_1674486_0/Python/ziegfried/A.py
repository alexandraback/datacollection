import sys,os
caseCount = int(sys.stdin.readline().strip())

def get_chain_ends(classes, cur, res = set()):
	next = classes[cur]
	if len(next):
		for n in next:
			get_chain_ends(classes, n, res)
	else:
		res.add(cur)

	return res

def find_diamond(classes):
	for c in classes:
		if len(c) >= 2:
			for i in c:
				x = get_chain_ends(classes,i, set())
				for j in c:
					if i != j:
						y = get_chain_ends(classes,j,set())
						if len(x & y):
							return "Yes"

	return "No"

for case in range(1,caseCount+1):
	result = None

	N = int(sys.stdin.readline().strip())

	classes = []

	for n in range(1,N+1):
		inh = [ int(x) for x in sys.stdin.readline().strip().split() ]
		M = inh[0]
		classes.append(tuple( x-1 for x in inh[1:] ))
	result = find_diamond(classes)

	print "Case #%d: %s" % (case, result)