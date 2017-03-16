for t in range(1, int(input()) + 1):
	x, r, c = map(int, input().split())
	ans = False
	if x < 7 and (r * c) % x == 0:
		if c < r:
			r, c = c, r
		if c >= x and r >= (x + 1) >> 1:
			if x < 4:
				ans = True
			else:
				ans = r > (x + 1) >> 1
	print('Case #%d: %s' % (t, 'GABRIEL' if ans else 'RICHARD'))