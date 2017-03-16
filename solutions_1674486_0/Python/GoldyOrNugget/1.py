

parents = [[] for i in xrange(1005)]


def solve(n):
	seen = set()

	def dfs(node):
		global out
		# print 'deal wit?', node
		if node in seen:
			return True
			
		
		seen.add(node)

		thing = False
		for p in parents[node]:
			thing |= dfs(p)
		return thing

	out = dfs(n)
	return out


def reset():
	global parents
	parents = [[] for i in xrange(1005)]



f = open('in.txt')
out = open('out.txt', 'w')
T = int(f.readline())
for i in xrange(T):

	reset()

	parented = set()

	N = int(f.readline())
	for j in xrange(N):
		c = map(int, f.readline().split())
		if (c[0] != 0):
			parents[j+1] = c[1:]
			parented.update(set(parents[j+1]))
	# roots = [ i for i in xrange(1, N+1) if parents[i] == [] ]
	desc = set(range(1, N+1)) - parented
	#print 'c', children
	ll = False
	for r in desc:
		ll |= solve(r)

	out.write('Case #%d: %s\n' % (i+1, 'Yes' if ll else 'No'))

