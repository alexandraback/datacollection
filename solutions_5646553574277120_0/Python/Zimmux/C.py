import fileinput
stdin = fileinput.input()

def solveCase():
	C,D,V = map(int,stdin.next().split())
	ds = map(int,stdin.next().split())
	# assuming C=1
	vs = [False]*(V+1)
	vs[0] = True
	n = 0
	used = 0
	for d in ds:
		for _ in xrange(C):
			for v in xrange(V,0,-1):
				if not vs[v] and v-d>=0 and vs[v-d]:
					vs[v] = True
					n += 1
	for i in xrange(V+1):
		if n==V:
			return used
		if not vs[i]:
			used += 1
			d = i
			for _ in xrange(C):
				for v in xrange(V,0,-1):
					if not vs[v] and v-d>=0 and vs[v-d]:
						vs[v] = True
						n += 1
	return used

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())