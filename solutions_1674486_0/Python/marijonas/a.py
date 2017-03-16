import sys, math, os, re
_tokiter = iter(sys.stdin.read().split()); get = lambda: next(_tokiter)
scanf = lambda *types: [t(get()) for t in types]

def testcase(id):
	N, = scanf(int)
	G = []
	All = []
	for i in xrange(N):
		m, = scanf(int)
		G.append(scanf(*([int] * m)))
		All.append([])
	#print G
	def mkall(i, All=All):
		if All[i]:
			return All[i]
		All[i] = [i]
		for t in G[i]:
			All[i].extend(mkall(t-1, All))
		return All[i]
		
	print 'Case #%d:' % id,
	for i in xrange(N):
		mkall(i)
		if len(All[i]) != len(set(All[i])):
			print 'Yes'
			return
	print 'No'


ncases, = scanf(int)
for i in xrange(ncases):
	print >>sys.stderr, 'Running case #%d' % (i+1)
	testcase(i+1)
