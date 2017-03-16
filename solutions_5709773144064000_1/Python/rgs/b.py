#!/usr/bin/env python

def costNaiveSum(C, F, k):
	return sum([C / (2 + i * F) for i in range(k)])

def costNaive(C, F, X, k):
	cost = costNaiveSum(C, F, k)
	cost += X / (2 + k * F)
	return cost

def testCost(C, F, X, k):
	# print "testCost", k
	costSum = costNaiveSum(C, F, k-1)
	costLeft = costSum + (X / (2 + (k-1) * F))
	costCenter = costSum + (C / (2 + (k-1) * F)) + (X / (2 + k * F))
	# costRight = costSum + (C / (2 + (k-1) * F)) + (C / (2 + k * F)) + (X / (2 + (k+1) * F))
	# print costLeft, costCenter #, costRight
	if costLeft <= costCenter:
		return False
	return True


t = input()
for ti in xrange(t):
	C, F, X = map(float, raw_input().split())
	#print [costNaive(C, F, X, k) for k in range(10)]

	l, r = 0, int(X)+2
	while l+1 < r:
		m = (l+r) / 2
		result = testCost(C, F, X, m)
		if result:
			l = m
		else:
			r = m
	ans = l
	print 'Case #' + str(ti+1) + ":", costNaive(C, F, X, ans)
