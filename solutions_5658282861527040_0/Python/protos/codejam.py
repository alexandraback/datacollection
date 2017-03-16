tcn = int(raw_input())

for tc in range(1, tcn + 1):
	a, b, k = tuple([int(x) for x in raw_input().split()])

	res = 0
	for i in range(a):
		for j in range(b):
			if i & j < k:
				res += 1

	print 'Case #%d: %d' % (tc, res)