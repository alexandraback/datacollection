
def stones(m, n):
	return 2*(m - 2) + 2*(n - 2)

def enclosed(m, n):
	return stones(m, n) + (m - 2)*(n - 2)

for testcase in xrange(input()):
	n, m, k = [int(_) for _ in raw_input().split()]
	if m < n:
		n, m = m, n
	# n <= m
	if k <= 4:
		ans = k
	elif n == 1: # 1 x m
		ans = k
	elif n == 2: # 2 x m
		ans = k
	elif k >= m * n - 4:
		ans = stones(m, n) + k - enclosed(m, n)
	else:
		ans = k
		for i in xrange(3, n + 1):
			for j in xrange(3, m + 1):
				for x in xrange(0, 5):
					if enclosed(i, j) + x >= k:
						ans = min(ans, stones(i, j) + x)
	print 'Case #{0}: {1}'.format(testcase + 1, ans)
