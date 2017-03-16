T = input()

for i in range(T):
	N = input()
	count = {}
	for _ in range(2 * N - 1):
		nums = map(int, raw_input().split())
		for n in nums:
			count[n] = count.get(n, 0) + 1

	print 'Case #%d:' % (i + 1), 
	ans = []
	for k, v in count.items():
		if v % 2 == 1:
			ans.append(k)
	print ' '.join(map(str, sorted(ans)))
