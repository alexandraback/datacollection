from sys import argv
from fractions import gcd
from math import sqrt

def simplify(pair):
	tmp = abs(gcd(pair[0], pair[1]))
	return (pair[0] / tmp, pair[1] / tmp)

def check_dist(vert, horiz):
	if vert < 0:
		v = bottom
		vdir = -1
	else:
		v = top
		vdir = 1

	if horiz < 0:
		h = left
		hdir = -1
	else:
		h = right
		hdir = 1

	vert = abs(vert)
	horiz = abs(horiz)
	if vert % 2 == 1:
		vtotal = v
		vert = (vert - 1) / 2
	else:
		vtotal = 0
		vert = vert / 2

	if horiz % 2 == 1:
		htotal = h
		horiz = (horiz - 1) / 2
	else:
		htotal = 0
		horiz = horiz / 2

	vtotal += vert * (top + bottom)
	htotal += horiz * (left + right)
	if htotal * htotal + vtotal * vtotal <= D2:
		points.append((hdir * htotal, vdir * vtotal))
		return True
	else:
		return False

f = open(argv[1], 'r')
T = int(f.readline().strip('\n'))
for i in range(T):
	H, W, D = map(int, f.readline().strip('\n').split(' '))
	lab = []
	for j in range(H):
		lab.append(f.readline().strip('\n'))

	D2 = D * D

	rdy = False
	H -= 2
	W -= 2
	for y in range(1,H + 1):
		for x in range(1, W + 1):
			if lab[y][x] == 'X':
				rdy = True
				px = x
				py = y
				break
		if rdy:
			break

	left = (px - 1) * 2 + 1
	right = (W - px) * 2 + 1
	top = (py - 1) * 2 + 1
	bottom = (H - py) * 2 + 1
	
	points = []
	last = -1
	curr = 0
	offset = 0
	while last != curr:
		points = []
		directions = set([])
		last = curr
		curr = 0
		offset += 1
		for x in xrange(-offset, offset + 1):
			for y in xrange(-offset, offset + 1):
				if not (x == 0 and y == 0) and check_dist(y,x):
					tmp = simplify((y,x))
					if tmp not in directions:
						curr += 1
						directions.add(tmp)


	points = sorted(points)
	print "Case #%s: %s" % (i + 1, curr)