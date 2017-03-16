import sys
import collections

f = open(sys.argv[1])

def check(root, children):
	visited = set()
	stack = [root]

	while stack:
		node = stack.pop()
		if node in visited: return True
		visited.add(node)
		for child in children[node]:
			stack.append(child)

	return False

for i in xrange(1, int(f.readline()) + 1):
	n = int(f.readline())
	nodes = set(k for k in xrange(1,n+1))
	parents = collections.defaultdict(lambda: set())
	children = collections.defaultdict(lambda: set())
	
	for node in xrange(1,n+1):
		ps = map(int, f.readline().split())[1:]
		for p in ps: 
			parents[node].add(p)
			children[p].add(node)

	roots = set(node for node in nodes if not parents[node])

	diamond = False
	for root in roots:
		if check(root, children):
			diamond = True
			break

	print "Case #%d: %s" % (i, "Yes" if diamond else "No")
