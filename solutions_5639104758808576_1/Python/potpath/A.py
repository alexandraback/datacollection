for t in range(1, int(input()) + 1):
	_, ks = input().split()
	ans = 0
	cum = 0
	for i, k in enumerate(ks):
		added = max(0, i - cum)
		ans += added
		cum += int(k) + added
	print('Case #%d: %d' % (t, ans))