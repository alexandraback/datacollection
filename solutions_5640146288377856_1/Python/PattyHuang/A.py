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
	else:
		if W==1:
			cnt = R*C
		else:
			max_v = max(R,C)
			min_v = min(R,C)
			if min_v > W:
				cnt = (min_v / W) * max_v
				if max_v % W != 0:
					cnt += 1
				if min_v % W != 0:
					cnt += 1
				cnt += W-1
			else:
				cnt = (max_v / W) * min_v
				if max_v % W != 0:
					cnt += 1
				if min_v % W != 0:
					cnt += 1
				cnt += W-1
	print 'Case #%d: %d ' % (t + 1, cnt)