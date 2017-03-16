import sys
inp = """4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21
2 1 2 2 2 1 0"""
if len(sys.argv) > 1:
	inp = open(sys.argv[1]).read().strip()

def sum(x):
	return reduce(lambda m,n: m+n, x)

def gen_score(t, want=0):
	if t == 0:
		if want <= 0:
			return [0,0,0], False
		else:
			return
	elif t == 1:
		if want <= 1:
			return [1,0,0], False
		else:
			return
	for i in xrange(10, -1, -1):
		# 1: the rest is i
		o = [i]*3
		if sum(o) == t and max(o) >= want:
			return (o, False)
		# 1: the rest is i-1
		o = [i, i-1, i-1]
		if sum(o) == t and max(o) >= want:
			return (o, False)
		# 2: the rest is i, i, i-1
		o = [i, i, i-1]
		if sum(o) == t and max(o) >= want:
			return (o, False)
	for i in xrange(10, -1, -1):
		# 3: the rest is i, i, i-2
		o = [i, i, i-2]
		if sum(o) == t and max(o) >= want:
			return (o, True)
		# 4: the rest is i-2
		o = [i, i-2, i-2]
		if sum(o) == t and max(o) >= want:
			return (o, True)
		# 5: the rest is (i-1, i-2)
		o = [i, i-1, i-2]
		if sum(o) == t and max(o) >= want:
			return (o, True)

for ln, l in enumerate(inp.split("\n")[1:]):
	l = [int(x) for x in l.split(" ")]
	out = 0
	sur = 0
	for no in l[3:]:
		sc = gen_score(no, l[2])
		if not sc:
			continue
		if sc[1] and sur < l[1]:
			sur += 1
			out += 1
			#print sc
		elif not sc[1]:
			out += 1
			#print sc
	print "Case #%s: %s"%(ln+1, out)