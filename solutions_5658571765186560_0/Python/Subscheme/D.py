getl = lambda: raw_input().split()
get = lambda: map(int, getl())

DIR = ((-1, 0), (1, 0), (0, 1), (0, -1))

def gen(r, c, x, s = False):
	global grid
	grid[r][c] = 1
	if c == C-1: s = True
	if x == 1:
		if s:
			yield r
	else:
		for dr, dc in DIR:
			if 0 <= r + dr < R and 0 <= c + dc < C and grid[r][c] == 0:
				for rows in gen(r + dr, c + dc, x - 1, s):
					yield max(rows, r)
	grid[r][c] = 0

def count():
	def dfs(r, c, v):
		if r < 0 or r >= R or c < 0 or C >= C or grid[r][c] == v: return 0
		grid[r][c] = v
		return 1 + sum(dfs(r + dr, c + dc, v) for dr, dc in DIR)
	a = sum(dfs(0, c, 2) for c in range(C))
	for c in range(C): dfs(0, c, 0)
	return a

def test(X, R, C):
	global grid
	if X > 7: return True
	if (R * C) % X != 0: return True
	if R + C + 1 <= X: return True
	if R < X and C < X: return True
	if (X - 1) / 2 >= R: return True
	grid = [[0]*C for r in range(R)]
	for rows in gen(0,0,X):
		c = count()
		win = True
		for r in range(R - rows):
			if (r*C + c) % X == 0:
				win = False
				break
		if win: return True
	return False

T, = get()
for testCase in range(1, T+1):
	X, R, C = get()
	print "Case #%d: %s" % (testCase, "RICHARD" if test(X, R, C) or test(X, C, R) else "GABRIEL")





