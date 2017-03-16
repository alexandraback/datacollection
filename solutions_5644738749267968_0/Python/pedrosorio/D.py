
T = int(raw_input())
for case in xrange(1,T+1):
	N = int(raw_input())
	naomi = sorted(map(float, raw_input().split()))
	ken = sorted(map(float, raw_input().split()))
	skipped = 0
	ki = 0
	for nchosen in naomi:
		while ki < N and ken[ki] < nchosen:
			skipped += 1
			ki += 1
		ki += 1
	ki = N - 1
	ni = 0
	nim = N - 1
	while ni <= nim:
		if naomi[nim] > ken[ki]:
			nim -= 1
		else:
			ni += 1
		ki -= 1

	print 'Case #' + str(case) + ': ' + str(N-1-nim) + ' ' + str(skipped)