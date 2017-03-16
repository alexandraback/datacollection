print 'B'

tests = open('tests.txt')
results = open('results.txt', 'w')

T = int(tests.readline())

# [int(x) for x in tests.readline().split()]

for t in xrange(1, T + 1):
	A, B, K = [int(x) for x in tests.readline().split()]
	count = 0
	for a in xrange(A):
		for b in xrange(B):
			if (a&b) < K:
				count += 1

	results.write('Case #' + str(t) + ': ' + str(count) + '\n')

