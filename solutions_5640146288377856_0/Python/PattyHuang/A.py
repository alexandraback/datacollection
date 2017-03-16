for t in range(int(raw_input())):
	cnt = 0
	R, C, W = map(int, raw_input().strip().split())
	if R==1:
		if W==1:
			cnt = C
		else:
			cnt = C / W + W-1
			if C % W != 0:
				cnt += 1
	print 'Case #%d: %d ' % (t + 1, cnt)