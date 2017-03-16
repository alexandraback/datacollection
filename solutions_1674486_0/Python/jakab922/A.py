from sys import argv

f = open(argv[1], "r")
T = int(f.readline().strip("\n"))

for i in xrange(T):
	N = int(f.readline().strip("\n"))
	edges = [[] for j in xrange(N + 1)]
	for j in xrange(1,N + 1):
		tmp = map(int, f.readline().strip("\n").split(" "))
		edges[j] = tmp[1:]

	for j in xrange(1, N + 1):
		was = [False for k in xrange(N + 1)]
		was[j] = True
		stack = [k for k in edges[j]]
		found = False
		while stack and not found:
			current = stack.pop()
			if was[current]:
				found = True
			else:
				was[current] = True
				for edge in edges[current]:
					stack.append(edge)
		if found:
			break
	if found:
		print "Case #%s: Yes" % (i + 1)
	else:
		print "Case #%s: No" % (i + 1) 
