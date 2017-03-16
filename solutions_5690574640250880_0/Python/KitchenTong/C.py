def generate(arena, r, c, R, C):
	for i in range(R):
		for j in range(C):
			if arena[i][j] != '*':
				arena[i][j] = '.'
	arena[r][c] = 'c'
	return '\n'.join([''.join(j for j in i) for i in arena])

def goTop(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goTop(arena, r-1, c, R, C)
	goLeft(arena, r, c-1, R, C)
	goRight(arena, r, c+1, R, C)
	go45(arena, r-1, c+1, R, C)
	go135(arena, r-1, c-1, R, C)

def goDown(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goDown(arena, r+1, c, R, C)
	goLeft(arena, r, c-1, R, C)
	goRight(arena, r, c+1, R, C)
	go225(arena, r+1, c-1, R, C)
	go315(arena, r+1, c+1, R, C)

def goLeft(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goTop(arena, r-1, c, R, C)
	goDown(arena, r+1, c, R, C)
	goLeft(arena, r, c-1, R, C)
	go135(arena, r-1, c-1, R, C)
	go225(arena, r+1, c-1, R, C)

def goRight(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goTop(arena, r-1, c, R, C)
	goDown(arena, r+1, c, R, C)
	goRight(arena, r, c+1, R, C)
	go45(arena, r-1, c+1, R, C)
	go315(arena, r+1, c+1, R, C)

def go45(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goTop(arena, r-1, c, R, C)
	goRight(arena, r, c+1, R, C)
	go45(arena, r-1, c+1, R, C)
	go135(arena, r-1, c-1, R, C)
	go315(arena, r+1, c+1, R, C)

def go135(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goTop(arena, r-1, c, R, C)
	goLeft(arena, r, c-1, R, C)
	go45(arena, r-1, c+1, R, C)
	go135(arena, r-1, c-1, R, C)
	go225(arena, r+1, c-1, R, C)

def go225(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goLeft(arena, r, c-1, R, C)
	goDown(arena, r+1, c, R, C)
	go135(arena, r-1, c-1, R, C)
	go225(arena, r+1, c-1, R, C)
	go315(arena, r+1, c+1, R, C)

def go315(arena, r, c, R, C):
	if r < 0 or r >= R or c < 0 or c >= C:
		return
	if arena[r][c] != '.':
		return

	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				n += 1
	if n > 0:
		arena[r][c] = str(n)
		return

	arena[r][c] = '-'
	goDown(arena, r+1, c, R, C)
	goRight(arena, r, c+1, R, C)
	go45(arena, r-1, c+1, R, C)
	go135(arena, r-1, c-1, R, C)
	go315(arena, r+1, c+1, R, C)

def click(arena, r, c, R, C):
	rows = [i for i in [r-1, r, r+1] if i >= 0 and i < R]
	cols = [i for i in [c-1, c, c+1] if i >= 0 and i < C]
	n = 0
	for i in rows:
		for j in cols:
			if arena[i][j] == '*':
				arena[r][c] = '8'
				for i in arena:
					if '.' in i:
						return False
				return True
	goTop(arena, r-1, c, R, C)
	goDown(arena, r+1, c, R, C)
	goLeft(arena, r, c-1, R, C)
	goRight(arena, r, c+1, R, C)
	go45(arena, r-1, c+1, R, C)
	go135(arena, r-1, c-1, R, C)
	go225(arena, r+1, c-1, R, C)
	go315(arena, r+1, c+1, R, C)
	for i in arena:
		if '.' in i:
			return False
	return True

def possible(arena, R, C):
	for (r, row) in enumerate(arena):
		for (c, location) in enumerate(row):
			if location == '.':
				arena[r][c] = 'c'
				if click(arena, r, c, R, C):
					return generate(arena, r, c, R, C)
				else:
					arena[r][c] = '.'
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