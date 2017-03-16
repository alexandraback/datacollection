import fileinput, math
stdin = fileinput.input()

M = 1000000007
fact = [math.factorial(n) for n in xrange(120)]

def solveCase():
	N = int(stdin.next())
	iN = xrange(N)
	ss = list(map(str,stdin.next().split()))
	# remove runs
	for i in iN:
		s = ss[i]
		s2 = ""
		l = ""
		for c in s:
			if c!=l:
				s2 += c
			l = c
		ss[i] = s2
	# check duplicate isolated characters
	iso = set()
	for s in ss:
		for c in s[1:-1]:
			if c in iso:
				return 0
			iso.add(c)
	for s in ss:
		if s[0] in iso or s[-1] in iso:
			return 0

	left  = set()
	pipe  = dict()
	right = set()
	for s in ss:
		if len(s)>1: # x...y
			if s[0] in left:
				return 0
			if s[-1] in right:
				return 0
			left.add(s[0])
			right.add(s[-1])
		else: # pipe
			if s[0] in pipe:
				pipe[s[0]] += 1
			else:
				pipe[s[0]] = 1
	mids = left & right
	outs = left | right
	# detect cycles: a..b b..c c..a
	byLeft = dict()
	for i in iN:
		if len(ss[i])>1:
			byLeft[ss[i][0]] = i
	for c in byLeft:
		cc = c
		while cc in byLeft:
			cc = ss[byLeft[cc]][-1]
			if c==cc: # cycle
				return 0
	# count components
	comps = 0
	for c in byLeft:
		if ss[byLeft[c]][-1] not in byLeft:
			comps += 1
	# restrictions on pipe positions
	n = fact[comps]
	for p in pipe:
		m = fact[pipe[p]]
		n *= m
		if p not in outs:
			n *= comps+1
			comps += 1
	return n%M

for case in xrange(int(stdin.next())):
	print "Case #{0}: {1}".format(case+1,solveCase())