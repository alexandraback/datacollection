def runTest(testNo, A, B, p):
	cache = []
	def correct_up_to_():
		prob = 1
		cache.append(prob)
		for i in xrange(A):
			prob *= p[i]
			cache.append(prob)
	correct_up_to_()
	def correct_up_to(n):
		return cache[n]
	
	result = 9999999
	v = correct_up_to(A) * (B-A+1) + (1 - correct_up_to(A)) * (B-A+1+B+1)
	#print '-'*80
	#print v
	result = min(result, v)
	for i in xrange(1,A+1):
		v = correct_up_to(A-i) * (2*i+B-A+1) + (1 - correct_up_to(A-i)) * (2*i+B-A+1+B+1)
		#print v
		result = min(result, v)
	v = 1+B+1
	result = min(result, v)
	print 'Case #' + str(testNo) + ': ' + str(result)

import sys

f = sys.stdin

tests = int(f.readline())

for test in xrange(tests):
	parts = f.readline().split(' ')
	p = map(float, f.readline().split(' '))

	runTest(test + 1, int(parts.pop(0)), int(parts.pop(0)), p)

