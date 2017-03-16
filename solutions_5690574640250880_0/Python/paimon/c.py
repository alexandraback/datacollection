from copy import deepcopy
from itertools import product

def solve(r, c, m):

	def find_pos(grid, border, count):
		
		def mark_cell(x, y):
			new_grid = deepcopy(grid)
			new_border = set(border) - {(x, y)}
			new_count = count
			for dx, dy in product((-1, 0, 1), repeat=2):
				x1, y1 = x + dx, y + dy
				if 0 <= x1 < r and 0 <= y1 < c and new_grid[x1][y1] == '*':
					new_grid[x1][y1] = '.'
					new_border.add((x1, y1))
					new_count += 1
			return new_grid, new_border, new_count
		
		rest = r*c - count
		if rest > m:
			for x, y in border:
				res_grid = find_pos(*mark_cell(x, y))
				if res_grid:
					return res_grid
		elif rest == m:
			return grid
		else:
			return None
				
	for i in range(r*c):
		x, y = divmod(i, c)
		grid = [['*']*c for i in range(r)]
		grid[x][y] = 'c'
		grid = find_pos(grid, {(x, y)}, 1)
		if grid: 
			return grid
	return None

fin, fout = open('c.in'), open('c.out', 'w')
answer = 'Case #{0}: '
t = int(fin.readline())
for i in range(t):
	r, c, m = map(int, fin.readline().split())
	grid = solve(r, c, m)
	print(answer.format(i + 1), file=fout)
	if grid:
		for row in grid:
			print(''.join(row), file=fout)
	else:
		print('Impossible', file=fout)
fin.close()
fout.close()
