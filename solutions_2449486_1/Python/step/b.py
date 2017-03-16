import os
import sys
# print "OK"
T = int(sys.stdin.readline())
def match(a,b):
	if a==b:
		return True
	if a == 'T' or b =='T':
		return True
	return False

for testcase in range(T):
	m = []
	result = "YES"
	(N,M) = [int(x) for x in sys.stdin.readline().split()]
	for l in xrange(N):
		line = sys.stdin.readline()[:-1]
		m.append( [int(x) for x in line.split() ] )

	try:
		for i in xrange(M):
			for j in xrange(N):
				v = m[j][i]
				good1 = True
				good2 = True
				for t in xrange(M):
					if m[j][t] > v:
						good1 = False
				for t in xrange(N):
					if m[t][i] > v:
						good2 = False
					
				if not (good1 or good2):
					raise "Ciao"
	except:
		result = "NO"
					

	print "Case #%d: %s" % (testcase+1, result)

    
