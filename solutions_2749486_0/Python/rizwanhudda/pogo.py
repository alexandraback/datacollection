def isConsonant(c):
	return False if c in 'aeiou' else True

T = input()
for case_no in range(1, T+1):
	x, y = map(int, raw_input().split())
	cx, cy, n = 0, 0, 1
	xc, yc, oxc, oyc, m = 'E', 'N', 'W', 'S', ''
	if x < 0:
		x *= -1
		xc, oxc = oxc, xc
	if y < 0:
		y *= -1
		yc, oyc = oyc, yc
	while cx < x:
		m += xc
		cx+= n
		n += 1
	while cx > x:
		m += xc
		m += oxc
		cx -= 1
		n += 2
	while cy < y:
		m += yc
		cy+= n
		n += 1
	while cy > y:
		m += yc
		m += oyc
		cy -= 1
		n += 2	
	print 'Case #%d: %s' % (case_no, m)