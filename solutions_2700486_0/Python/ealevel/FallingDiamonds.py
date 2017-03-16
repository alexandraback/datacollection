import sys
sys.setrecursionlimit(10001)

def rolldown_left(diamonds, x, y):
	if y > 0 and (x-1, y-1) not in diamonds:
		return rolldown_left(diamonds, x-1, y-1)
	return (x, y)

def rolldown_right(diamonds, x, y):
	if y > 0 and (x+1, y-1) not in diamonds:
		return rolldown_right(diamonds, x+1, y-1)
	return (x, y)

def simulate(falling, diamonds):
	if falling == 0:
		global count, tot
		tot += 1
		if (X, Y) in diamonds:
			count += 1
		return

	maxY = 0
	for x, y in diamonds:
		if x == 0 and y > maxY:
			maxY = y

	y = maxY
	a, b = False, False
	if (+1, y+1) not in diamonds:
		a = True
		xr, yr = rolldown_right(diamonds, +1, y+1)
		diamonds.append((xr, yr))
		simulate(falling - 1, diamonds)
		diamonds.pop()
	if (-1, y+1) not in diamonds:
		b = True
		xr, yr = rolldown_left(diamonds, -1, y+1)
		diamonds.append((xr, yr))
		simulate(falling - 1, diamonds)
		diamonds.pop()
	if not a and not b:
		diamonds.append((0, y + 2))
		simulate(falling - 1, diamonds)
		diamonds.pop()

T = int(sys.stdin.readline().strip())
for t in xrange(1, T+1):
	N, X, Y = map(int, sys.stdin.readline().strip().split())
	
#	A = [1]
#	while A[-1] <= 1e6:
#		A.append(2 * A[-1] + 3)
#	print A
	
	count = 0.0
	tot = 0.0
	simulate(N-1, [(0, 0)])
	print "Case #{}: {}".format(t, count / tot)
