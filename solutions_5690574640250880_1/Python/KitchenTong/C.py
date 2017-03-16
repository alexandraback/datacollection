def generate(arena, r, c, R, C):
	for i in range(R):
		for j in range(C):
			if arena[i][j] != '*':
				arena[i][j] = '.'
	arena[r][c] = 'c'
	return '\n'.join([''.join(j for j in i) for i in arena])

def check(arena, r, c, R, C):
	rows = [i for i in [r, r-1, r+1] if i >= 0 and i < R]
	cols = [i for i in [c, c-1, c+1] if i >= 0 and i < C]
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				return True
	return False

def go(arena, r, c, R, C):
	if arena[r][c] == '.':
		if check(arena, r, c, R, C):
			arena[r][c] = '1'
		else:
			arena[r][c] = '-'
	return

def click(arena, R, C):
	if check(arena, 0, 0, R, C):
		arena[0][0] = '1'
	else:
		arena[0][0] = '-'

	for i in xrange(R):
		for j in xrange(C):
			if arena[i][j] == '-':
				rows = [_ for _ in [i, i-1, i+1] if _ >= 0 and _ < R]
				cols = [_ for _ in [j, j-1, j+1] if _ >= 0 and _ < C]
				for x in rows:
					for y in cols:
						go(arena, x, y, R, C)

	for i in arena:
		if '.' in i:
			return False
	return True

def possible(arena, R, C):
	if click(arena, R, C):
		return generate(arena, 0, 0, R, C)
	return ""

def getArena(R, C, M):
	import math
	space = R * C - M

	base = int(math.sqrt(space))
	extra = space - (base * base)
	arena = [['*' for i in range(C)] for j in range(R)]

	if R > base and C > base:
		for i in range(base):
			for j in range((space - extra) / base):
				arena[i][j] = '.'
		if extra > base:
			for i in range(base):
				arena[i][base] = '.'
			extra = extra - base
			if extra == 1:
				extra += 1
				arena[base-1][base] = '*'
			for i in range(extra):
				arena[base][i] = '.'
		else:
			if extra == 1:
				extra += 1
				arena[base-1][base-1] = '*'
			for i in range(extra):
				arena[base][i] = '.'
	else:
		if R > C:
			extra = space % C
			height = (space - extra) / C
			for i in range(height):
				for j in range(C):
					arena[i][j] = '.'
			if extra == 1:
				extra += 1
				arena[height-1][C-1] = '*'
			for i in range(extra):
				arena[height][i] = '.'
		else:
			extra = space % R
			width = (space - extra) / R
			for i in range(R):
				for j in range(width):
					arena[i][j] = '.'
			if extra == 1:
				extra += 1
				arena[R-1][width-1] = '*'
			for i in range(extra):
				arena[i][width] = '.'
	return arena

def res(R, C, M):
	arena = getArena(R, C, M)
	if arena:
		ans = possible(arena, R, C)
	else:
		return "Impossible"
	if ans:
		return ans
	return "Impossible"

if __name__ == "__main__":
	T = int(raw_input())
	for t in xrange(T):
		R, C, M = map(int, raw_input().split())
		print "Case #%d:\n%s" % (t+1, res(R, C, M))