for t in range(1, int(input()) + 1):
	d = int(input())
	ps = sorted(map(int, input().split()))
	ans = ps[-1]
	at = 0
	for i in range(1, ps[-1]):
		while ps[at] <= i:
			at += 1
		cum = i
		for p in ps[at:]:
			cum += int((p + i - 1) / i) - 1
			if cum >= ans:
				break
		else:
			ans = cum
	print('Case #%d: %d' % (t, ans))