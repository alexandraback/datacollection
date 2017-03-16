
T = input()
for t in range(T):
	cin = map(int, raw_input().split())
	N, S, p, score_sums = cin[0], cin[1], cin[2], cin[3:]

	ans = 0
	for score_sum in score_sums:
		if score_sum >= (p-1) * 3 + 1:
			ans += 1
		elif score_sum >= (p-2) * 3 + 2 and S > 0 and p-2 >= 0:
			ans += 1
			S -= 1
	print 'Case #%d: %d' % (t+1, ans)
