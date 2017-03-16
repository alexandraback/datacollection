import sys

def dbg(s): pass #sys.stderr.write(str(s))
def dbgn(s): dbg(str(s) + "\n")

def read(t): return t(raw_input())
def reads(t): return map(t, raw_input().split(" "))


#~ def bksp(A, B, k, p):
	#~ g = B - A
	#~ n = (k*2 + g)
	#~ pr = 1
	#~ for i in xrange(A-k):

	


T = read(int)

for t in xrange(1, T+1):
	(A, B) = reads(int)
	p = reads(float)
	
	eks = []
	
	g = (B - A)

	# A bksp
	n = 2 * A + (g + 1)
	dbgn("k pr n" + str((A, 1, n)))
	eks.append(n)

	pr = 1
	for i in xrange(A):
		# k bksp
		pr = p[i] * pr
		k = A - (i+1)
		if k > 0:
			n = (2 * k + g + 1)
			dbgn("k i pr n" + str((k, i, pr, n)))
			eks.append(n * pr + (n + B +1) * (1-pr))
		
	
	#keep
	ag = (g + 1) * pr + (g + 1 + B + 1) * (1-pr)
	#~ ag = 1 * pr + 2* g* (1 - pr)
	dbgn(ag)
	eks.append(ag)
	
	# enter right away
	if A == B:
		n = 1 * pr + (B + 2) (1 - pr)
		eks.append(n)
		dbgn(n)
	else:
		n = B + 2
		eks.append(n)
		dbgn(n)
	
	dbgn(eks)
	print "Case #%d: %s" % (t, min(eks))
