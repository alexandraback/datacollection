import fileinput
stdin = fileinput.input()

def pretty(grid):
	return "\n".join(map(''.join,grid))

def solveNums(l,h,e):
	if e==1:
		return 1,0,0,1
	if l==1:
		return e,0,0,e
	for x in xrange(2,h+1):
		for y in xrange(2,l+1):
			occ = x*y-(x-2)*(y-2)
			if occ<=e<=x*y:
				return e,x,y,e-occ
	return -1,0,0,0

def solveCase():
	r, c, m = map(int,stdin.next().split())
	e = r*c-m
	l,h = min(r,c), max(r,c)
	
	k,xx,yy,ee = solveNums(l,h,e)
	if k!=e:
		return "Impossible"

	grid = [['*' for x in xrange(h)] for y in xrange(l)]
	if xx<2 and yy<2:
		x,y = 0,0
		for i in xrange(ee):
			grid[y][x] = '.'
			x += 1
			if x==h:
				x = 0
				y += 1
	else:
		for y in xrange(yy):
			grid[y][0] = '.'
			grid[y][1] = '.'
		for x in xrange(xx):
			grid[0][x] = '.'
			grid[1][x] = '.'
		x,y = 2,2
		for i in xrange(ee):
			grid[y][x] = '.'
			x += 1
			if x==xx:
				x = 2
				y += 1
	grid[0][0] = 'c'

	if r>c:
		grid = zip(*grid)
	return pretty(grid)

for case in xrange(int(stdin.next())):
	print "Case #{0}:\n{1}".format(case+1,solveCase())