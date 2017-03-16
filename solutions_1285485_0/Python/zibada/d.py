from fractions import gcd

def solve():
	global w, h, a, sx, sy
	h, w, d = map(int, raw_input().split())
	a = [raw_input() for _ in xrange(h)]
	for i in xrange(h):
		j = a[i].find('X')
		if j == -1: continue
		sx, sy = j, i
		break
	res = set()
	for dx in xrange(-d, d + 1):
		for dy in xrange(-d, d + 1):
			if dx ** 2 + dy ** 2 > d * d: continue
			if dx == 0 and dy == 0: continue
			if trace(sx + dx, w) == sx and trace(sy + dy, h) == sy:
				x, y = dx, dy
				if x == 0: y /= abs(y)
				elif y == 0: x /= abs(x)
				else:
					g = gcd(abs(x), abs(y))
					x /= g
					y /= g
				res.add((x, y))
	return len(res)
		
def trace(x, w):
	x -= 1
	w -= 2
	x %= 2 * w
	if x < w: return x + 1
	return 2 * w - x	
	
for i in xrange(input()):
	print "Case #%d: %d" % (i + 1, solve())
