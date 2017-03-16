import sys, math, os, re
_tokiter = iter(sys.stdin.read().split()); get = lambda: next(_tokiter)
scanf = lambda *types: [t(get()) for t in types]

def testcase(id):
	n, = scanf(int)
	j = scanf(*([int]*n))
	jorig = list(j)
	j.sort()
	s = sum(j)
	nlvl = 0
	for i in xrange(n):
		lvl = (sum(j[:i+1]) + s) / (i + 1.0)
		if max(j[:i+1]) > lvl:
			break
		nlvl = lvl
	print 'Case #%d:' % id,
	for ji in jorig:
		if ji >= nlvl:
			print 0.0,
		else:
			print '%.6f' % (100.0 * ((nlvl - ji) / s)),
	print


ncases, = scanf(int)
for i in xrange(ncases):
	print >>sys.stderr, 'Running case #%d' % (i+1)
	testcase(i+1)
